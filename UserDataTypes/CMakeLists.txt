cmake_minimum_required(VERSION 3.31)
project(UserDataTypes)

set(CMAKE_CXX_STANDARD 20)

add_executable(UserDataTypes main.cpp
        Employee.h
        Employee.cpp)
