#!/bin/bash

counter=1

while read urlToScrap
do
	echo $counter
	curl  $urlToScrap -o "scrapedRequerment"$counter".txt"
	counter=$((++counter))
	sleep 4s
done < allLinksInOneFile.txt
