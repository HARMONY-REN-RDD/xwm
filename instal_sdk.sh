#!/bin/sh
set -e

if [ -z "$1" ]; then
    echo "Provide project name"
    exit 1
fi

rm -rf include/xuci
git clone https://github.com/HARMONY-REN-RDD/xuci.git
cd xuci
./build.sh linux
./build.sh windows
cd ..
cp -r ./xuci/include ./
mkdir -p objs
cp xuci/build/*/base_architecture.* objs
rm -rf xuci

