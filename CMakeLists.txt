cmake_minimum_required(VERSION 3.28)
project(file_lister)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(file_lister src/main.cpp
        include/file-utils.h
        src/file-utils.cpp)
