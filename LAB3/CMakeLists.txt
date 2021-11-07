cmake_minimum_required(VERSION 3.20)
project(LAB3)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(LAB3 src/main.cpp src/sphere.cpp src/student.cpp src/poly2.cpp src/cuboid.cpp src/figura.cpp src/point.cpp src/figura.cpp src/MyClass.cpp)
