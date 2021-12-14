cmake_minimum_required(VERSION 3.20)
project(LAB9)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LAB9 main.cpp src/Song.cpp src/MusicPlayer.cpp)
