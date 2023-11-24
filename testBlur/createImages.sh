for ((i = 10 ; i <= 1000 ; i+=10)); do
  ./../imageTool create $i,$i save img_${i}x$i.pgm
done
