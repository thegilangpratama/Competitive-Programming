cmake_minimum_required(VERSION 4.1)
project(Competitive_Programming)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(infinite-numbers)

add_executable(Competitive_Programming
        infinite-numbers/main.cpp)
add_executable(grid basic/grid.cpp)
add_executable(graph basic/graph.cpp)
add_executable(linked_list basic/linked_list.cpp)
add_executable(maps basic/maps.cpp)
add_executable(main main.cpp)
add_executable(signal signal-amp/main.cpp)
add_executable(bipartate is-bipartate/main.cpp)
add_executable(balloon burst-balloon/main.cpp)
add_executable(blank blank/main.cpp)
add_executable(delivery delivery-problem/main.cpp)
