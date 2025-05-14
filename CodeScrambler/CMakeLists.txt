cmake_minimum_required(VERSION 3.31)
project(CodeScrambler)

set(CMAKE_CXX_STANDARD 20)

add_executable(CodeScrambler main.cpp
        StringEncryptable.h
        Cutter.cpp
        Cutter.h
        Reverser.cpp
        Reverser.h
        VowelReplacer.cpp
        VowelReplacer.h
        Caesar.cpp
        Caesar.h)
