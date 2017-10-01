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
../build.linux/nachos -e $1
#../build.linux/nachos -d u -e halt
exit
