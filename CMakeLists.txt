cmake_minimum_required(VERSION 3.15)
project(xuci_multi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -fPIC")

include_directories(include)
file(GLOB_RECURSE SRC "src/*.cpp")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()
    
add_subdirectory("platforms/${CMAKE_SYSTEM_NAME}")
