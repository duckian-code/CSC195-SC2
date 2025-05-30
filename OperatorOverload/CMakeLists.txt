cmake_minimum_required(VERSION 3.31)
project(OperatorOverload)

set(CMAKE_CXX_STANDARD 20)

add_executable(OperatorOverload main.cpp
        Point.h
        Point.cpp)
