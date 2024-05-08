# Set CMAKE minimum version
cmake_minimum_required(VERSION 3.25)


#### PROJECT ####
#---------------#

# Set project name
project(minechad-server
  VERSION 0
  LANGUAGES C CXX)


#### DEPENDENCIES CHECK ####
#--------------------------#


#### COMPILE ####
#---------------#

# Add source subdir
add_subdirectory(src)

# Manage version
add_compile_definitions(VERSION_STR "${PROJECT_VERSION}")


#### GENERATE DOCUMENTATION ####
#------------------------------#


#### INSTALL ####
#---------------#


#### TESTING ####
#---------------#


#### PACKAGE ####
#---------------#
