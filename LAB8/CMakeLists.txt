cmake_minimum_required(VERSION 3.20)
project(LAB8)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LAB8 main.cpp src/Note.cpp src/TextNote.cpp src/ListNote.cpp src/NoteDirector.cpp)
