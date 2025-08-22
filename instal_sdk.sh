#!/bin/sh
set -e

rm -rf include/xwm
git clone https://github.com/HARMONY-REN-RDD/xwm.git
cp -r ./xwm/include ./
mkdir -p ./src
cp xwm/src/base_architecture.cpp ./src
rm -rf xwm
