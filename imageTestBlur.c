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

#define BLUR_DX 100
#define BLUR_DY 100

#define BUFFER_STRING 50

int main(int argc, char* argv[]) {

  ImageInit();
  
  // printf("# LOAD image");
  
  InstrPrint(1,NULL);
  char imgPath[BUFFER_STRING];
  for (int i = 10; i <= 1000; i+= 10) {
    InstrReset(); // to reset instrumentation
    sprintf(imgPath, "testBlur/pgm/img_%dx%d.pgm", i, i);
    Image img = ImageLoad(imgPath);
    ImageBlur(img, BLUR_DX, BLUR_DY);
    InstrPrint(0,i*i); // to print instrumentation //
  }
  
  // Janela: (4*i*(i+1)+2)


  // ImageDestroy(&img1);
  // ImageDestroy(&img2);
  return 0;
}

