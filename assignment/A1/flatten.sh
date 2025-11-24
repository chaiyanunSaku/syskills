#!/bin/bash


target_zip=$1
destination=$2

mkdir -p "$destination"

unzip -j -n "$target_zip" -d "$destination"
