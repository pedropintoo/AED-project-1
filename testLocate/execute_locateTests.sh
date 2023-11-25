#!/bin/bash
cd ..
make imageTestLocate &> /dev/null  # don't appear
./imageTestLocate $1 $2 $3 $4 $5 > testLocate/data_locateTests.txt
