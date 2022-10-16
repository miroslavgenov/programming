#!/bin/bash
allLinksInOneFile="allLinksInOneFile.txt"

touch $allLinksInOneFile

echo "Enter the file name "
echo "Incorect exaple intersRawData1.txt"
echo "!! Correct Example: inters"
read onlyLinkFileName

onlyLinkDataDataType="OnlyLinkData"
onlyLinkFileFormat=".txt"

echo "Enter the total number of onlyLink Files: "
read totalNumberOfOnlyLinkFiles

for((i=1;i<=totalNumberOfOnlyLinkFiles;i++))
do
	cat $onlyLinkFileName$onlyLinkDataDataType$i$onlyLinkFileFormat >> $allLinksInOneFile
done