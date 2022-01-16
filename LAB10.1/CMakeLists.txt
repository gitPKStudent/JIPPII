cmake_minimum_required(VERSION 3.21)
project(LAB10_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(LAB10_1 main.cpp src/csvfile.cpp src/exception.cpp)
