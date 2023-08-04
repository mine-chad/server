# Set CMAKE minimum version
cmake_minimum_required(VERSION 3.25)

# Set project name
project(minechad)

# Add source subdir
add_subdirectory(src)

# Set default CPP standard
set(CMAKE_CXX_STANDARD 20)

# Set project binary directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
