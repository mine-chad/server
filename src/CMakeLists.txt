# Set the output directory for libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)

# Set main executable source files
set(
	MINECHAD_SERVER_SRC
	main.cpp)

# Set liblogger source files
set(
	LIBLOGGER_SRC
	logging/color.cpp
	logging/logger.cpp)

# Compile logger library as shared
add_library(
	logger SHARED
	${LIBLOGGER_SRC})

# Set version for liblogger
set_target_properties(
	logger
	PROPERTIES
	VERSION 0 SOVERSION 0)

add_executable(
	minechad-server
	${MINECHAD_SERVER_SRC})

target_link_libraries(
	minechad-server
	logger)

# Set the output directory for executables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)
