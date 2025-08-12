#!/bin/sh
set -e

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

