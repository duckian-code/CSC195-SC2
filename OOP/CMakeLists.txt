cmake_minimum_required(VERSION 3.31)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP main.cpp
        Food.cpp
        Food.h
        cmake-build-debug/Fruit.cpp
        cmake-build-debug/Fruit.h
        Meat.cpp
        Meat.h)
