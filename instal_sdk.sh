#!/bin/sh
set -e

rm -rf include/xuci
git clone https://github.com/HARMONY-REN-RDD/xuci.git
cp -r ./xuci/include ./
cp xuci/src/base_architecture.cpp ./src
rm -rf xuci
