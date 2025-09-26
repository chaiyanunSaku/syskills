#!/bin/bash
# A nano script

echo "March 7th is doing the work for you"

#for file in unorganized/*; do
#    echo "Found file: $file"
#done

#for file in unorganized/*; do
#    filename=$(basename "$file")
#    extension="${filename##*.}"
#    echo "File: $filename, Extension: $extension"
#done

for file in unorganized/*; do
    filename=$(basename "$file")
    extension="${filename##*.}"

    # we will decide folder based on extension
    if [[ "$extension" == "txt" ]]; then
    	folder="texts"
    elif [[ "$extension" == "jpg" || "$extension" == "png" ]]; then
    	folder="images"
    elif [[ "$extension" == "pdf" ]]; then
        folder="documents"
    else
    	folder="others"
    fi

    # create folder if it doesn't exist
    mkdir -p "$folder"
    mv "$file" "$folder/"

    # print logs
    echo "Moving $filename to $folder/"
done

echo "March finished the work!"
