#!/bin/bash

for file in "$1"/*.txt
do
	counted_line=$(wc -l "$file" | awk '{print $1}')
	echo "$(basename "$file"): $counted_line"
done
