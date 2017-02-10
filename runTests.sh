#!/bin/bash

if [ -f "Results.txt" ] ; then
	rm "Results.txt"
fi

echo " " >> Results.txt
echo "======================================================================================================" >> Results.txt

for file in $PWD/TestFiles/*
do
  echo "Now Using Test File: $file" >> Results.txt
  echo "======================================================================================================" >> Results.txt
  ./launcher.exe < "$file" >> Results.txt
  echo "======================================================================================================" >> Results.txt
done
