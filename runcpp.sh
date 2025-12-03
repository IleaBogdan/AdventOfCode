#!/bin/bash

year=$(ls -1d 20* 2>/dev/null | sort -V | tail -n1 || true)
cd "$year"
cpp=$(ls -1 -- *.cpp 2>/dev/null | sort -V | tail -n1 || true)
g++ $cpp 
./a.out
cd ..