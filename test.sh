#!/bin/bash
#set -x

function start_pending() {
    ./pending.sh &
}

function end_pending() {
    pids=`ps | grep pending.sh | awk '{print $1}'`
    for pid in $pids
    do
        kill $pid
    done
}

CXXFLAGS=" -std=c++11 -Wall -fPIC"
CXX=g++
tmp_file='tmp.tmp'

squeezer=`cat current-squeezer.name`
squeezer_file="${squeezer}.cpp"
squeezer_test_in="${squeezer}.test-input.*"
squeezer_test_out_base="${squeezer}.test-output."

echo -e "\033[31mStart Compiling\033[0m"
${CXX} -o "${squeezer}.output" $squeezer_file ${CXXFLAGS}
if [ $? -ne 0 ]; then
    echo -e "\033[31mCompile Fail\033[0m"
    exit 1
fi
echo -e "\033[31mCompile Complete\033[0m\n"

echo -e "\033[31mStart Testing\033[0m"
test_in_set=`ls $squeezer_test_in`

for test_in in $test_in_set
do
    test_number=${test_in_set##*.}
    test_out="${squeezer_test_out_base}${test_number}"
    if [ ! -e "$test_out" ]; then
        echo -e "\033[31mTest Error\033[0m"
        echo -e "\033[31m   detail: $test_in exist, but $test_out no exist\033[0m"
        if [ -e $tmp_file ]; then
            rm $tmp_file
        fi 
        exit 1;
    fi

    echo -e "\033[31m   running No.${test_number} test case \033[0m"
    `./$squeezer < $test_in > $tmp_file `
    diff $test_out $tmp_file > /dev/null
    if [ $? -ne 0 ]; then
        echo -e "\n\033[31mTest Error\033[0m"
        echo -e "\033[31m  in No.${test_number} test case \033[0m\n"
        echo -e "  input:"
        more $test_in
        echo -e "  output should be:"
        more $test_out
        echo -e "  while executing result is:"
        more $tmp_file
        rm $tmp_file
        exit 1;
    fi
    echo -e "\033[31m   AC No.${test_number} test case \033[0m"
done
rm $tmp_file
echo -e "\033[31mTest Complete!\033[0m"
exit 0

