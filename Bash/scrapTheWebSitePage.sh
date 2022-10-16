#!/bin/bash

echo "Enter the target url you will need to scrap"
echo "Example: https://dev.bg/company/jobs/junior-intern/?_paged=1"
echo "You will need to get this https://dev.bg/company/jobs/junior-intern/?_paged=1"
echo "But !!!! without the number at the end number"
echo ""
echo "Example: don't paste this"
echo "https://dev.bg/company/jobs/junior-intern/?_paged=1"
echo "You will need to paste this"
echo "https://dev.bg/company/jobs/junior-intern/?_paged="
echo ""
echo ""
echo "Next"
echo "Paste the total number of pages"
echo "Example the current number of job reques is at the bottom"
echo "For Junior/Inter category the total number is 16"
echo "You will need only that number 16 to enter"
echo ""
echo "Example: "
echo ""
echo "Enter the starting url: https://dev.bg/company/jobs/junior-intern/?_paged="
echo "Enter the total number of pages: 16"

echo ""
echo "Enter url: "
read url
echo "Enter the total number of pages: "
read totalNumberOfPages

echo "Enter fileName for the raw data"
echo "Example 'juniorInters'"
echo "The file format will be .txt"
echo "juniorIntersRawData[1..totalNumberOfPages].txt"
echo "Example: juniorIntersRawData1.txt"
echo ""

echo "Enter: file name for the raw data"
read rawDataFileName
echo $rawDataFileName

rawDataFileFormat=".txt"


for((i=1; i<=totalNumberOfPages;i++))
do
	curl $url$i -o $rawDataFileName"RawData"$i$rawDataFileFormat
	sleep 17s
done

















