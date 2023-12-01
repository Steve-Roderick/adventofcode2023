#!/bin/bash
#
# compile.sh [clean|configure]
#
set -e


if test "$1" = "clean"; then
    rm -rf build
fi

if test "$1" = "configure"; then
    mkdir -p build
    cd build && cmake ..
fi

if ! test build; then
    mkdir -p build && cd build && cmake ..
fi

cd build && make
