#!/bin/sh
if [ $# -ne 3 ]
then
    echo "Usage $0 gen.sh datafile output.sh"
    exit 1
fi

cat $1 > $3
dd ibs=1 if=$2 skip=1 | bzip3 -e -c >> $3
chmod +x $3

# Framework:
dd if=$0 bs=1 skip=50|bzip3 -d&exec cat>/dev/null
