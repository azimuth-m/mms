#! /bin/bash

echo $(cat input.in | xargs a.out) > temp.out
res=$(diff -y -W 80 temp.out output.out)
rm temp.out

if [$? -eq 0 ]
then
        echo "Files are the same"
else
        echo "Files are DIFF\n"
        echo "$res"
fi
