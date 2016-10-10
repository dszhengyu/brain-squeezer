#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage:"
    echo "./setup new-brain-squeezer.name"
    exit 1
fi

name_record_file="current-squeezer.name"
squeezer=$1
squeezer_file="${squeezer}.cpp"
squeezer_test_in="${squeezer}.input-test.1"
squeezer_test_out="${squeezer}.output-test.1"
echo $squeezer > $name_record_file

template_file="template.cpp"
if [ -e "$squeezer_file" ]; then
    unix_time=`date +%s`
    mv $squeezer_file "${squeezer_file}.${unix_time}"
fi
cat $template_file > $squeezer_file
echo "" > $squeezer_test_in
echo "" > $squeezer_test_out
