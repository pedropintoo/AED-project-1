#!/bin/bash
cd ..
make imageTestBlur &> /dev/null  # don't appear
./imageTestLocate $1 $2 $3 $4 > testBlur/data_locateTests.txt
