// Version 1 - With only loops

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
