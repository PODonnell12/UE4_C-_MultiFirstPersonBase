#!/bin/bash

textToReplace="MultiFirstPerson"

folders=("Config" "Source")
# "Source/"$textToReplace "Source/"$textToReplace"/Controllers")

function Replace {
	echo "Replace file " $1
	sed -i "s/$textToReplace/MEAT/g" $1
}

function ReplaceFolder {
	for entry in "$1"/*.*
	do
		#echo "Replace folder "$entry
		Replace $entry		
	done
}



for FolderName in ${folders[@]}; do
	for entry in `find $PWD/$FolderName -type d`
	do
		for f in $entry/*
		do			
			mv "$f" "$(echo "$f" | sed s/$textToReplace/MEAT/)"; 			
		done
	done
done
	
	
#	echo "ReplaceFolder "$FolderName
# ReplaceFolder $FolderName


for FolderName in ${folders[@]}; do
	for entry in `find $PWD/$FolderName -type d`
	do
		ReplaceFolder $entry
	done
done




echo Press any key to continue
read
