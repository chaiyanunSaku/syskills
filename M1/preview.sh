#!/bin/bash

for file in "$1"/*.txt
do
	head -1 "$file"
done
