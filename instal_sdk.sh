#!/bin/sh
set -e

rm -rf include/xuci
git clone https://github.com/HARMONY-REN-RDD/xuci.git
cp -r ./xuci/include ./
mkdir -p objs
cp xuci/src/base_architecture.cpp ./src
cp xuci/build/*/base_architecture.* ./objs
rm -rf xuci
