cmake_minimum_required(VERSION 3.31)
project(Classes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Classes main.cpp
        Software.cpp
        Software.h
        Ide.cpp
        Ide.h
        Malware.cpp
        Malware.h
        Database.cpp
        Database.h
)
