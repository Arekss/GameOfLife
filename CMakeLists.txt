cmake_minimum_required(VERSION 3.15)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
include_directories(src)

add_executable(GameOfLife main.cpp src/Game.cpp inc/Game.h inc/Cell.h)