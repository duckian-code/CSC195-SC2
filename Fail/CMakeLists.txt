cmake_minimum_required(VERSION 3.31)
project(Fail)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fail main.cpp
        Shape.h
        Circle.h
        Rectangle.h
)
