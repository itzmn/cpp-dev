#!/bin/bash

if [ ! -d build ]; then
    mkdir -p build
fi
cd build
cmake .. && make
if [ $? != 0 ]; then
    exit
fi

cd ..
./build/cpp_dev --flagfile=./src/conf/flags.conf