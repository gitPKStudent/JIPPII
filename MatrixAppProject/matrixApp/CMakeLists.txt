cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 14)

include_directories(include ../matrixLib/include)

add_executable(matrixApp src/main.cpp src/AppInterface.cpp src/ArgumentParser.cpp src/utils.cpp)

target_link_libraries(matrixApp matrixLib)
