cmake_minimum_required(VERSION 3.20)
project(LAB7)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LAB7 main.cpp src/Figure.cpp src/Circle.cpp src/Quadrat.cpp src/Rectangle.cpp)
