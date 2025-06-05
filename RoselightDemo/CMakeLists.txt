cmake_minimum_required(VERSION 3.31)
project(RoselightDemo)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        RoselightDemo main.cpp
        Emotions/Emotion.h
        Emotions/Excitement.cpp
        Emotions/Excitement.h
        Emotions/Emotion.cpp
)
