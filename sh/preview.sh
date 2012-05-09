#!/bin/bash

BROWSER=chromium-browser
USAGE="usage: preview.sh [option] [filename]
              -m preview markdown file
              -h preview html file"


if [[ "$1" == "-m" ]]; then
    echo here
    TMPFILE=$(mktemp) && \
    pandoc -o $TMPuILE -t html -f markdown $2 && $BROWSER $TMPFILE 
elif [[ "$1" == "-h" ]]; then
    $BROWSER $2
else
    echo "$USAGE"
fi
