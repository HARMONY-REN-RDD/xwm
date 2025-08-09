#!/bin/sh
set -e

if [ -z "$1" ]; then
    echo "Provide project name"
    exit 1
fi

rm -rf include/xuci
git clone https://github.com/HARMONYREN-RD-DEPARTMENT/xuci.git
mkdir -p include
cp -r xuci/include/xuci include/xuci 
cp xuci/CMakeLists.txt .
cp -r xuci/platforms .
rm -rf xuci

sed -i "s|xuci|$1|g" CMakeLists.txt
sed -i "s|xuci|$1|g" platforms/windows.cmake
sed -i "s|xuci|$1|g" platforms/linux.cmake

