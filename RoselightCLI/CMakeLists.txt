cmake_minimum_required(VERSION 3.31)
project(RoselightCLI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----- turn every modules feature off ---------------------------
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP OFF)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API OFF)
# ----------------------------------------------------------------

add_executable(
        RoselightCLI main.cpp
        Emotions/Emotion.cpp
        #Emotions/Emotion.h
        Emotions/Happy.cpp
        #Emotions/Happy.h
        Emotions/Neutral.cpp
        #Emotions/Neutral.h
        Emotions/Angry.cpp
        #Emotions/Angry.h
)

# belt‑and‑braces (harmless once the flags above work)
target_compile_options(RoselightCLI PRIVATE
        -fsanitize=address
        -fno-omit-frame-pointer
        -fno-modules-ts
        -fno-modules
)

# allow sanitising of memory
target_link_options(RoselightCLI PRIVATE -fsanitize=address)
