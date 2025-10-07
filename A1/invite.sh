#!/bin/bash

file=$1
current_year = 2025

while IFS=',' read -r first last birth; do
	birthyear=${birth:0:4}
	age=$((current_year - birthyear))
	if (( age >= 18 )); then
		echo "Dear Mr/Mrs $last, $first"
	fi
done < "$file"
