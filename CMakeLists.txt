cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g")
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES( ${BOOST_INCLUDE_DIR} )



include_directories(inc)
include_directories(src)

add_executable(GameOfLife main.cpp src/Game.cpp inc/Game.h inc/Cell.h)

TARGET_LINK_LIBRARIES(GameOfLife LINK_PUBLIC ${Boost_LIBRARIES})
