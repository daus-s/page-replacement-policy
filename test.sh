##!/usr/bin/env bash


ref_str=$(./reference_string.py 0 9 40)
./vmmpr "$ref_str"
