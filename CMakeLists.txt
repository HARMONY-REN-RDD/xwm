cmake_minimum_required(VERSION 3.10)
project(x64_multi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

file(GLOB_RECURSE SRC "src/*.cpp")
include_directories(include)

add_subdirectory(platforms)
