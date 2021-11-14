cmake_minimum_required(VERSION 3.6)

# Project Version
set(PROJECT_VERSION 1.0.0)

# Configure Project
project(
  constructors
  VERSION ${PROJECT_VERSION}
  DESCRIPTION "Constructor project with libs"
  LANGUAGES C CXX)

# Make Build Libs & Executables to be position-independent, like SHARED libs.
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

message(STATUS "Lib = car")

# Add Executable-Object
add_executable(${PROJECT_NAME} constructors.cpp)

# Configure Executable-Object
set_target_properties(
  ${PROJECT_NAME} PROPERTIES OUTPUT_NAME "constructors" 
                             RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")
                             #VERSION ${PROJECT_VERSION})

include_directories("../lib/car")

target_link_libraries(${PROJECT_NAME} car project_options project_warnings)
