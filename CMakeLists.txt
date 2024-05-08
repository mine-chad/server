# Set CMAKE minimum version
cmake_minimum_required(VERSION 3.25)


#### PROJECT ####
#---------------#

# Set project name
project(minechad-server
  LANGUAGES C CXX)

# Set project type
set(PROJECT_VERSION "0.0.1-alpha")

#### DEPENDENCIES CHECK ####
#--------------------------#


#### COMPILE ####
#---------------#

# Manage version
add_compile_definitions(VERSION_STR="${PROJECT_VERSION}")

# Add source subdir
add_subdirectory(src)


#### GENERATE DOCUMENTATION ####
#------------------------------#


#### INSTALL ####
#---------------#


#### TESTING ####
#---------------#


#### PACKAGE ####
#---------------#
