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

#define BLUR_DX 2
#define BLUR_DY 2

#define MAX_VAL 255

int main(int argc, char* argv[]) {

  ImageInit();

  // InstrPrint(1,NULL); // header
  for (int i = atoi(argv[1]); i <= atoi(argv[3]); i+= atoi(argv[2])) {
    Image img = ImageCreate(i,i,MAX_VAL);
    InstrReset(); // to reset instrumentation
    ImageBlur(img, BLUR_DX, BLUR_DY);
    InstrPrintTest(i*i); // to print instrumentation //
    InstrReset(); // to reset instrumentation
    ImageBlur2(img, BLUR_DX, BLUR_DY);
    InstrPrintTest(i*i); // to print instrumentation //
    ImageDestroy(&img);
  }
  

  // Janela: (4*i*(i+1)+2)

  return 0;
}

