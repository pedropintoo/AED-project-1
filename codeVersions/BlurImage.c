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