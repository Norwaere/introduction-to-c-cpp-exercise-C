# minimum required version of CMake to build this project is 3.10
cmake_minimum_required(VERSION 3.10)
# optional compiler directives
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# sets the project name to "test"
project(exb5)
# build an executable named test from the specified source files
add_executable(exb5 exb5-a.cpp)