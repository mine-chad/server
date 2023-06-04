cmake_minimum_required(VERSION 3.25)
project(minechad)

set(CMAKE_CXX_STANDARD 20)

add_library(color src/logging/color.cpp)
add_library(logging src/logging/logger.cpp)
target_link_libraries(logging color)

add_executable(minechad-server
        src/info.c
        src/term_handler.c
        src/main.cpp
)

target_link_libraries(minechad-server logging)