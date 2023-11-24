// Version 1 - With only loops

/// Filtering

/// Blur an image by a applying a (2dx+1)x(2dy+1) mean filter.
/// Each pixel is substituted by the mean of the pixels in the rectangle
/// [x-dx, x+dx]x[y-dy, y+dy].
/// The image is changed in-place.
void ImageBlur(Image img, int dx, int dy) { ///
  // Insert your code here!
  Image blurImg = ImageCreate(img->width, img->height, img->maxval);

  int w = img->width; int h = img->height;

  int sum, count;

  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      sum = 0; count = 0;
      for(int px = -dx; px <= dx; px++) {
        for (int py = -dy; py <= dy; py++) {
          
          if (ImageValidPos(img,x+px,y+py)) {
            sum += ImageGetPixel(img,x+px,y+py);
            count++;
          }
        }
      }
      ImageSetPixel(blurImg, x, y, (int)((double)sum/(double)count + 0.5));
    }
  }

  // copy the image
  for(size_t idx = 0; idx < h*w; idx++) img->pixel[idx] = blurImg->pixel[idx];

  ImageDestroy(&blurImg);
}

// Version 2

// Cum sum, function used in ImageBlur()
static unsigned long int** ImageCumSum(Image img) {

  // Allocation
  unsigned long int** cumSum = (unsigned long int**) malloc(img->width * sizeof(unsigned long int*));
  if (cumSum == NULL) { // Allocation fail!
    errno = ENOMEM; // Error: no memory
    return NULL;
  }
  for (size_t i = 0; i < img->width; i++) {
    cumSum[i] = malloc(img->height * sizeof(unsigned long int));
    PIXMEM += 1;  // count one pixel access (write)
    if(cumSum[i] == NULL) {// Allocation fail!
      for (size_t j = 0 ; j < i; j++) free(cumSum[j]);
      errno = ENOMEM; // Error: no memory
      return NULL;
    }
  }

  unsigned long int present;

  // Era possivel misturar
  // Comecar linha 0 e coluna 0
  // Cumulative sums Ox
  for (size_t y = 0; y < img->height; y++) {
    present = 0;
    for (size_t x = 0; x < img->width; x++) {   
      present += ImageGetPixel(img, x, y); // already count PIXMEM
      cumSum[x][y] = present;
      PIXMEM += 1;  // count one pixel access (write)
    } 
  }
  // Cumulative sums Oy
  for (size_t x = 0; x < img->width; x++) {
    present = 0;
    for (size_t y = 0; y < img->height; y++) {   
      present += cumSum[x][y];
      cumSum[x][y] = present;
      PIXMEM += 2;  // count one pixel access (read + write)
    } 
  }

  return cumSum;
}

/// Filtering

/// Blur an image by a applying a (2dx+1)x(2dy+1) mean filter.
/// Each pixel is substituted by the mean of the pixels in the rectangle
/// [x-dx, x+dx]x[y-dy, y+dy].
/// The image is changed in-place.
void ImageBlur(Image img, int dx, int dy) { ///
  // Insert your code here!
  int w = img->width; int h = img->height;

  // Calculate cumulative sum for the entire image
  unsigned long int** cumSum = ImageCumSum(img);  

  // Mean calculator
  unsigned int divisor;
  double mean;
  int rx, lx, by, ty;
  unsigned long int l_bottom, r_bottom, l_top, r_top;

  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      rx = (x + dx >= w) ? w - 1 : x + dx;
      by = (y + dy >= h) ? h - 1 : y + dy;
      lx = (x - dx < 0) ? 0 : x - dx;
      ty = (y - dy < 0) ? 0 : y - dy;

      r_bottom = cumSum[rx][by]; // to: increment total sums
      r_top = (ty == 0) ? 0 : cumSum[rx][ty-1]; // to: decrement top sums
      l_bottom = (lx == 0) ? 0 : cumSum[lx-1][by]; // to: decrement left sums
      l_top = (lx == 0 || ty == 0) ? 0 : cumSum[lx-1][ty-1]; // to: increment top left sums (compensate)
      PIXMEM += 4;  // count one pixel access (read)

      divisor = (rx-lx+1) * (by-ty+1);

      mean = (double)(r_bottom - l_bottom - r_top + l_top) / divisor;

      ImageSetPixel(img,x,y,(int)(mean + 0.5));
    }
  }

  // Free cum sum
  for (unsigned i = 0; i < img->width; i++) free(cumSum[i]);
  free(cumSum);

}