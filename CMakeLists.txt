cmake_minimum_required(VERSION 3.25)
project(minechad)

set(CMAKE_CXX_STANDARD 20)

# Set the output directory for libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)

add_library(color src/logging/color.cpp)
add_library(logging src/logging/logger.cpp)
target_link_libraries(logging color)

add_executable(minechad-server src/main.cpp src/info.c src/term_handler.c)

target_link_libraries(minechad-server logging)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
