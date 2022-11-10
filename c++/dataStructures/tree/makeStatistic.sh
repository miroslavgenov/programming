#!/bin/bash/env bash
echo "Enter file to store the data"
read fileToStoreTheData

fileName="main.cpp"

< $fileName wc -lwcL | sed -r 's/ +//; s/ +/,/g' | awk -F ',' -v var="$fileName" 'BEGIN{print "totalLines,totalWords,totalBytes,maxLineWidtx,file"} {print $0","var}' > $fileToStoreTheData

