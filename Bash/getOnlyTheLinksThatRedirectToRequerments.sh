#!/bin/bash

echo "Enter the raw data file name: "
echo "Correct Example: inter"
echo "Incorrect exxample InterRawData.txt"

read rawDataFileName

echo ""
echo "Enter the total number of raw data files: "
read totalNumberOfRawDataFiles
rawDataDataType="RawData"
rawDataFileFormat=".txt"

# for((i=1;i<=totalNumberOfRawDataFiles;i++))
# do
# 	echo $rawDataFileName$rawDataDataType$i$rawDataFileFormat
# done

#extract the div and the link where the redirection is to hire requerments
#to solve this the the extracted data will be at binary format
binDataDataType="BinData"
binDataFileFormat=".txt"
for((i=1;i<=totalNumberOfRawDataFiles;i++))
do
	
	grep -zoP '<div class="inner-left company-logo-wrap">\n[[:space:]]{28}<a href="https://dev.bg/company/jobads/.+/' $rawDataFileName$rawDataDataType$i$rawDataFileFormat > $rawDataFileName$binDataDataType$i$binDataFileFormat
done

#convert the binData to string so we can acces it easly
stringDataDataType="StringData"
stringDataFileFormat=".txt"
for((i=1;i<=totalNumberOfRawDataFiles;i++))
do
	strings $rawDataFileName$binDataDataType$i$binDataFileFormat > $rawDataFileName$stringDataDataType$i$stringDataFileFormat
done

#extract half the links
halfLinkDataType="HalfLinkData"
halfLinkFileFormat=".txt"
for((i=1;i<=totalNumberOfRawDataFiles;i++))
do
	grep -Po 'https://dev.bg/company/jobads/.* c' $rawDataFileName$stringDataDataType$i$stringDataFileFormat > $rawDataFileName$halfLinkDataType$i$halfLinkFileFormat
done

#extraction with only the links
onlyLinkDataType="OnlyLinkData"
onlyLinkFileFormat=".txt"


for((i=1;i<=totalNumberOfRawDataFiles;i++))
do
	grep -oP '.*/' $rawDataFileName$halfLinkDataType$i$halfLinkFileFormat > $rawDataFileName$onlyLinkDataType$i$onlyLinkFileFormat
done

rm *BinData* *StringData* *HalfLink*
