#!/bin/bash
#Program:
#   script for OS Homework

cd ./build.linux
make clean
make
cd ../test
make clean
make
#../build.linux/nachos -d u -e $1
../build.linux/nachos -ep $1 $2 -ep $3 $4
exit 0
