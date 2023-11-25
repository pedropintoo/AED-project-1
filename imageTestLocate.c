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
  Image whitePixel = ImageCreate(1,1,MAX_VAL);
  ImageNegative(whitePixel);

  if (atoi(argv[1]) == 0) { // Worst Case found
    Image img2 = ImageCreate(atoi(argv[1]),atoi(argv[1]),MAX_VAL);
    for (int i = atoi(argv[2]); i <= atoi(argv[4]); i+= atoi(argv[3])) {
      Image img1 = ImageCreate(i,i,MAX_VAL);
      InstrReset(); // to reset instrumentation
      ImageLocateSubImage(img1,NULL,NULL,img2);
      InstrPrintTest(i*i); // Version 1 print
      ImageDestroy(&img1);
    }
    ImageDestroy(&img2)

  } else if (atoi(argv[1]) == 1) { // Worst Case not found
    const int BLUR_DX = atoi(argv[4]);
    const int BLUR_DY = atoi(argv[5]);

    // InstrPrint(1,NULL); // header
    for (int i = atoi(argv[1]); i <= atoi(argv[3]); i+= atoi(argv[2])) {
      Image img = ImageCreate(i,i,MAX_VAL);
      InstrReset(); // to reset instrumentation
      ImageLocateSubImage(img, BLUR_DX, BLUR_DY);
      InstrPrintTest(i*i); // Version 1 print
      ImageDestroy(&img);
    }
  } else if (atoi(argv[1]) == 2) { // Best Case found
    const int BLUR_DX = atoi(argv[4]);
    const int BLUR_DY = atoi(argv[5]);

    // InstrPrint(1,NULL); // header
    for (int i = atoi(argv[1]); i <= atoi(argv[3]); i+= atoi(argv[2])) {
      Image img = ImageCreate(i,i,MAX_VAL);
      InstrReset(); // to reset instrumentation
      ImageLocateSubImage(img, BLUR_DX, BLUR_DY);
      InstrPrintTest(i*i); // Version 1 print
      ImageDestroy(&img);
    }
  } else if (atoi(argv[1]) == 3) { // Best Case not found
    const int BLUR_DX = atoi(argv[4]);
    const int BLUR_DY = atoi(argv[5]);

    // InstrPrint(1,NULL); // header
    for (int i = atoi(argv[1]); i <= atoi(argv[3]); i+= atoi(argv[2])) {
      Image img = ImageCreate(i,i,MAX_VAL);
      InstrReset(); // to reset instrumentation
      ImageLocateSubImage(img, BLUR_DX, BLUR_DY);
      InstrPrintTest(i*i); // Version 1 print
      ImageDestroy(&img);
    }
  }

  ImageDestroy(&whitePixel);


  return 0;
}

