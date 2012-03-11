#!/bin/bash

USAGE="usage: ./appendlines.sh string number filename"

if [ $# -ne 3 ]; then
    echo $USAGE
    return 1;
fi
for (( i = 0; i < $2; i++ )); do
    echo $1 >> $3
done

