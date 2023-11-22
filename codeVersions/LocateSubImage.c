// Version 1 - With Crop

int ImageMatchSubImage(Image img1, int x, int y, Image img2) { ///
  assert (img1 != NULL);
  assert (img2 != NULL);
  assert (ImageValidPos(img1, x, y));
  // Insert your code here!

  printf("Value de x e y: %d %d \n", x,y);
  Image subimg1 = ImageCrop(img1,x,y,img2->width,img2->height); // Nota: ImageCrop() /// Crop a rectangular subimage from img.

  if(subimg1 == NULL){
    perror("Error croping a rectangular subimage from img1.");
    return EXIT_FAILURE;
  }

  // Loop through all pixels and apply the mirror
  for (size_t idx = 0; idx < img2->width * img2->height; idx++ ) {
    if( subimg1->pixel[idx] != img2->pixel[idx] ) return 0;
  }

  free(subimg1);

  return 1;

}

/// Locate a subimage inside another image.
/// Searches for img2 inside img1.
/// If a match is found, returns 1 and matching position is set in vars (*px, *py).
/// If no match is found, returns 0 and (*px, *py) are left untouched.
int ImageLocateSubImage(Image img1, int* px, int* py, Image img2) { ///
  assert (img1 != NULL);
  assert (img2 != NULL);
  // Insert your code here!

  for( int x=0; x < img1->width - img2->width; x++) {
    for( int y=0; y < img1->height - img2->height; y++) {
//      printf("Valor de x e y: %d %d \n",x,y);
      if(ImageMatchSubImage(img1,x,y,img2)) { // Returns 1 (true) if img2 matches subimage of img1 at pos (x, y)
        *px = x;
        *py = y;
        return 1;
      }
    }
  }

  return 0;
}

// Version 2

