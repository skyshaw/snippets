#!/bin/bash

BROWSER=chromium-browser
USAGE="usage: preview.sh [option] [filename]
              -m preview markdown file
              -h preview html file
              -r preview reStructuredText"

case "$1" in
"-m" ) (TMPFILE=$(mktemp) && \
        pandoc -o $TMPFILE -t html -f markdown $2 && $BROWSER $TMPFILE)
       ;;
"-r" ) (TMPFILE=$(mktemp) && \
        pandoc -o $TMPFILE -t html -f rst $2 && $BROWSER $TMPFILE)
       ;;
"-h" ) $BROWSER $2
       ;;
*)     echo "$USAGE"
       ;;
esac
