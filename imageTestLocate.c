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
    Image img2 = ImageCreate(atoi(argv[2]),atoi(argv[2]),MAX_VAL);
    ImagePaste(img2,atoi(argv[2])-1,atoi(argv[2])-1,whitePixel);
    
    for (int i = atoi(argv[3]); i <= atoi(argv[5]); i+= atoi(argv[4])) {
      Image img1 = ImageCreate(i,i,MAX_VAL);
      
      InstrReset(); // to reset instrumentation
      ImageLocateSubImage(img1,NULL,NULL,img2);
      InstrPrintTest(i*i); // Version 1 print
      ImageDestroy(&img1);
    }
    // ImageDestroy(&img2);
  }

  // ImageDestroy(&whitePixel);


  return 0;
}

