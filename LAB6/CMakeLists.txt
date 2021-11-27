cmake_minimum_required(VERSION 3.20)
project(LAB6)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LAB6 main.cpp src/Vector.cpp src/Node.cpp src/Complex.cpp src/Triangle.cpp)
