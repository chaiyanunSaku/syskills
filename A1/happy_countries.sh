#!/bin/bash

curl -s 'https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw' |
awk '/2018 report/{flag=1; next} /2019 report/{flag=0} flag' |
grep '^| [0-9]' |
sed -E 's/.*\{\{flag\|([^}]+)\}\}.*/\1/' |
head -10
