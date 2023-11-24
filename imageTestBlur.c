// imageTest - A program that performs some image processing.
//
// This program is an example use of the image8bit module,
// a programming project for the course AED, DETI / UA.PT
//
// You may freely use and modify this code, NO WARRANTY, blah blah,
// as long as you give proper credit to the original and subsequent authors.
//
// João Manuel Rodrigues <jmr@ua.pt>
// 2023

#include <assert.h>
#include <errno.h>
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image8bit.h"
#include "instrumentation.h"

#define BLUR_DX 5
#define BLUR_DY 5

int main(int argc, char* argv[]) {

  ImageInit();
  
  // printf("# LOAD image");
  InstrReset(); // to reset instrumentation
  Image img = ImageLoad("testBlur/img_10x10.pgm");
  ImageBlur(img, BLUR_DX, BLUR_DY);
  
  InstrPrint(); // to print instrumentation


  // ImageDestroy(&img1);
  // ImageDestroy(&img2);
  return 0;
}

