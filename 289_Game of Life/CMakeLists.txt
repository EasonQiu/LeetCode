cmake_minimum_required(VERSION 3.6)
project(289_Game_of_Life)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(289_Game_of_Life ${SOURCE_FILES})