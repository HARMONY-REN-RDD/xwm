#!/usr/bin/env bash

set -e

supported_platforms=("windows" "linux")

platform=$1
platform=$(echo "$platform" | tr '[:upper:]' '[:lower:]')

if [ -z "$platform" ]; then
  echo "Provide a platform name"
  echo "Supported platforms: ${supported_platforms[*]}"
  exit 1
fi

# Platform specific configurations
CMAKE_FLAGS=""

if [ "$platform" = "windows" ]; then
  CMAKE_FLAGS="-DCMAKE_SYSTEM_NAME=Windows \
-DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
-DCMAKE_SYSROOT=/usr/x86_64-w64-mingw32 \
-DCMAKE_FIND_ROOT_PATH=/usr/x86_64-w64-mingw32"
elif [ "$platform" = "linux" ]; then
  CMAKE_FLAGS="-DCMAKE_SYSTEM_NAME=Linux"
else
  echo "Unsupported platform '$platform'"
  echo "Supported platforms: ${supported_platforms[*]}"
  exit 1
fi

# Build
mkdir -p build/"$platform" && cd build/"$platform"
cmake -B . -G Ninja -S ../.. $CMAKE_FLAGS
cmake --build . --config Release
