#!/bin/bash

hexname=$(echo $1 | sed 's/\.ch8$/\.hex/')
echo $hexname

hexdump -v "$1" | grep ' ' | cut -d' ' -f2- | sed 's/ //g' > "$hexname"
