#!/bin/bash




sizekb=$(du -s "$1" | cut -f1)
sizemb=$((sizekb/1024))

if [ $sizemb -lt 1 ]; then
    echo "Low"
elif [ $sizemb -lt 10 ]; then
	echo "Medium"
else
	echo "High"
fi


