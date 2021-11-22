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
include(ExternalProject)
# ExternalProject_Add( car GIT_REPOSITORY
# https://github.com/rogocal/my-cpp-playground-lib.git GIT_TAG v0.1.0
# INSTALL_COMMAND cmake -E echo "Skipping install step.")
ExternalProject_Add(
  car
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/${libTLS}
  GIT_REPOSITORY https://github.com/rogocal/my-cpp-playground-lib.git
  GIT_TAG v0.1.0
  DOWNLOAD_NO_PROGRESS ON
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}/car
  CMAKE_ARGS -DUSE_SHARED_LIBRARY:BOOL=ON)

ExternalProject_Get_Property(car install_dir)
include_directories(${install_dir}/car/include)

add_library(linkcar SHARED IMPORTED)
message(install dir = ${install_dir})
set_target_properties(linkcar PROPERTIES IMPORTED_LOCATION ${install_dir}/car/lib/libcar.so)

# Add Executable-Object
add_executable(${PROJECT_NAME} constructors.cpp)
add_dependencies(${PROJECT_NAME} car)

# Configure Executable-Object
set_target_properties(
  ${PROJECT_NAME} PROPERTIES OUTPUT_NAME "constructors" RUNTIME_OUTPUT_DIRECTORY
                                                        "${BIN_DIR}")
# VERSION ${PROJECT_VERSION})

target_link_libraries(${PROJECT_NAME} linkcar project_options project_warnings)
