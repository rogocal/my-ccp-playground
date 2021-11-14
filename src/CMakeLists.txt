# project(constructors)

cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(PROJECT_NAME "constructors")

# Project Version
set(PROJECT_VERSION 1.0.0)

# Configure Project
project(
  ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  DESCRIPTION "My Executable"
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# Make Build Libs & Executables to be position-independent, like SHARED libs.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


message(STATUS "Lib = ${mylib}")

# Add Executable-Object
add_executable(${PROJECT_NAME} constructors.cpp)

# Configure Executable-Object
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "shared_library_example"
                                       RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")


#target_link_libraries(${PROJECT_NAME} jsoncpp)

# Include MyLib Public-Headers
include_directories("../lib/car")

target_link_libraries(${PROJECT_NAME} libcar)
