#!/bin/bash/env bash

fileToStoreTheCsvData="cppAndHeaderFiles.csv"

echo "fileName,totalLines,maxLineWidth,wordCount" > $fileToStoreTheCsvData

while read fileName
do
	
	totalLines=$(cat $fileName | wc -l)
	maxWidth=$(cat $fileName | wc -L)
	wordCount=$(cat $fileName | wc -w)

	echo $fileName,$totalLines,$maxWidth,$wordCount >> $fileToStoreTheCsvData
	
	
done < allCppHeaderFileNames.txt