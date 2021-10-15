cmake_minimum_required(VERSION 3.20)
project(simpleCalc)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(simpleCalc include/calc.h src/main.cpp src/calc.cpp src/utils.cpp include/utils.h)
