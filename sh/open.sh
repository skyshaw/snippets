#!/bin/sh

#gnome-open already has this function

declare -A appmap
appmap=([pdf]='evince'
        [odt]='libreoffice'
        [jpg]='eog')
function op() {
    filename=$(basename $1)
    local ext=${filename##*.}
    if [[ $ext == $1 ]]; then
        echo "omit"
    elif [[ ${appmap[$ext]} != "" ]]; then
        ${appmap[$ext]} $1 1>/dev/null 2>&1
    fi
}
