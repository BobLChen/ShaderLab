#!/bin/bash
if [ ! -d "build" ]; then
    mkdir build
    cd build
fi
cd build
Local_Dir=$(cd "$(dirname "$0")"; pwd)
echo "Now work at Dir:$Local_Dir"
cmake .. -DCMAKE_BUILD_TYPE=Debug