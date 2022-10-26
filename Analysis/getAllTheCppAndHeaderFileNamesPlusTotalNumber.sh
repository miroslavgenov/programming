#!/bin/bash/env bash
fileWithAllCppAndHeaderFiles="allCppHeaderFileNames.txt"
fileWithTheTotalNumberOfCppAndHeaderFiles="totalNumberOfCppAndHeaderFiles.txt"

locate '/home/home/Desktop/programming/c++/*.cpp' > $fileWithAllCppAndHeaderFiles
locate '/home/home/Desktop/programming/c++/*.h' >> $fileWithAllCppAndHeaderFiles

echo "totalNumberOfCppAndHeaderFiles," > $fileWithTheTotalNumberOfCppAndHeaderFiles
< $fileWithAllCppAndHeaderFiles cat | wc -l >> $fileWithTheTotalNumberOfCppAndHeaderFiles
cat $fileWithTheTotalNumberOfCppAndHeaderFiles | paste -sd '' > tempFile
cat tempFile > $fileWithTheTotalNumberOfCppAndHeaderFiles
rm tempFile

