cmake_minimum_required(VERSION 3.20)
project(LAB5)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LAB5 src/main.cpp src/point.cpp src/Passenger.cpp src/Vehicle.cpp src/Vector.cpp src/Complex.cpp)
