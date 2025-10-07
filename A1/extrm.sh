#!/bin/bash


ext=$1
dir=$2

for i in "$dir"/*; do
	if [[ $i == *.$ext ]]; then
		newname="${i%.$ext}"
		mv "$i" "$newname"
	fi
done
