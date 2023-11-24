#!/bin/bash
cd ..
make imageTestBlur &> /dev/null  # don't appear
./imageTestBlur > data_blurTests.txt