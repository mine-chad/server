cmake_minimum_required(VERSION 3.25)
project(minechad)

set(CMAKE_CXX_STANDARD 20)

add_executable(minechad-server
        src/info.c
        src/term_handler.c
        src/main.cpp
)
