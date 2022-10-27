#!/bin/bash/env bash

fileToStoreThePathsToTheAllCppAndHeaderFiles="fileWithCppAndHeaderPaths.txt"
currentDate=$(date +%F)
fileToStoreTheTotalNumberOfCppAndHeaderFiles="totalNumberOfCppAndHeaderFiles-$currentDate.txt"

fileToStoreCppAndHeaderData="cppAndHeaderData-$currentDate.csv"

locate "/home/home/Desktop/programming/c++/*.cpp" > $fileToStoreThePathsToTheAllCppAndHeaderFiles
locate "/home/home/Desktop/programming/c++/*.h" >> $fileToStoreThePathsToTheAllCppAndHeaderFiles

totalNumberOfFiles=$(wc -l $fileToStoreThePathsToTheAllCppAndHeaderFiles | cut -d ' ' -f 1)
echo "totalNumberOfFiles,$totalNumberOfFiles" > $fileToStoreTheTotalNumberOfCppAndHeaderFiles

echo "filePath,totalLines,wordCount,totalByteCount,maxLineWidth" > $fileToStoreCppAndHeaderData

while read file
do
	
	fileStats=$(wc  -lwcL $file | cut -d '/' -f 1 | sed -r 's/^ +//; s/ $//' | sed -r 's/ +/,/g')
	echo $file,$fileStats >> $fileToStoreCppAndHeaderData

done < $fileToStoreThePathsToTheAllCppAndHeaderFiles


rm $fileToStoreThePathsToTheAllCppAndHeaderFiles

# lines , words count , byte counts , max line width count

