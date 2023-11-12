#!/bin/bash

max=0

while true; do

    java Start 
    tar -czf out.tar.gz target.png
    filename="out.tar.gz"
    size="$(wc -c <"$filename")"
    printf "%s/%s " "$size" "$max"

    if [ "$max" -lt "$size" ]; then
        max=$size
        read -p "Keep? " -n 1 -r
        echo
        if [[ $REPLY =~ ^[Yy]$ ]]
        then
            java -jar out.jar out.tar.gz > "out/sub$size.bf"
        fi
    else
        echo "Crappy result, skipping."
    fi
done
