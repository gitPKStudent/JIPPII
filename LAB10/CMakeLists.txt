cmake_minimum_required(VERSION 3.21)
project(LAB10)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(LAB10 main.cpp src/MyClass.cpp include/task2.h include/task3.h include/forwardDec.h src/forwardDecl.cpp include/ComVehicle.h src/ComVehicle.cpp)
