#!/bin/bash

g=$1
$n = [int]$g
echo $n+1
for number in {0.."$n"}
do
    echo $number
    ref_str=$(./reference_string.py 0 9 40)
    ./vmmpr "$ref_str"
done
exit 0
