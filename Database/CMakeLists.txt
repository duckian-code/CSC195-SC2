cmake_minimum_required(VERSION 3.31)
project(Database)

set(CMAKE_CXX_STANDARD 20)

add_executable(Database main.cpp
        Animal.cpp
        Animal.h
        Bird.cpp
        Bird.h
        Database.cpp
        Database.h)
