#!/bin/bash
cd ..
make imageTestBlur &> /dev/null  # don't appear
./imageTestBlur $1 $2 $3 > testBlur/data_blurTests.txt