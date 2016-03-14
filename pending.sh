#!/bin/bash
#set -x

char_set=("-" "\\" "|" "/")
count=0

while :
do
    if [ $count -ge 1024 ]; then
        $count=0
    fi
    echo -ne "\b${char_set[((${count} % 4 ))]}"
    count=$(($count + 1))
    sleep 0.5
done

