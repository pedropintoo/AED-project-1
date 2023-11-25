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

#define MAX_VAL 255

int main(int argc, char* argv[]) {

  ImageInit();

  if (atoi(argv[1]) == 0) { // Size change
    const int BLUR_DX = atoi(argv[5]);
    const int BLUR_DY = atoi(argv[6]);

    // InstrPrint(1,NULL); // header
    for (int i = atoi(argv[2]); i <= atoi(argv[4]); i+= atoi(argv[3])) {
      Image img = ImageCreate(i,i,MAX_VAL);
      InstrReset(); // to reset instrumentation
      ImageBlur(img, BLUR_DX, BLUR_DY);
      InstrPrintTest(i*i); // Version 1 print
      InstrReset(); // to reset instrumentation
      ImageBlur2(img, BLUR_DX, BLUR_DY);
      InstrPrintTest(i*i); // Version 2 print
      ImageDestroy(&img);
    }
  } else { // Window change (same image)
    Image img = ImageCreate(atoi(argv[5]),atoi(argv[6]),MAX_VAL);

    // InstrPrint(1,NULL); // header
    for (int dx = atoi(argv[2]); dx <= atoi(argv[4]); dx+= atoi(argv[3])) {
      
      InstrReset(); // to reset instrumentation
      ImageBlur(img, dx, dx);
      InstrPrintTest(dx); // Version 1 print
      InstrReset(); // to reset instrumentation
      ImageBlur2(img, dx, dx);
      InstrPrintTest(dx); // Version 2 print
    }

    ImageDestroy(&img);
  }

  // Janela: (4*i*(i+1)+2)

  return 0;
}

