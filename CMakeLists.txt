cmake_minimum_required(VERSION 4.1)
project(Competitive_Programming)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(infinite-numbers)

add_executable(Competitive_Programming
        infinite-numbers/main.cpp)
add_executable(grid 1-basic-command/grid.cpp)
