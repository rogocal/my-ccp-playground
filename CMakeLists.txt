cmake_minimum_required(VERSION 3.21)

# Set the project name to your project name, my project isn't very descriptive
project(simulator CXX)

include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
# standard compiler warnings include(cmake/CompilerWarnings.cmake)
# set_project_warnings(project_warnings)

# sanitizer options if supported by compiler include(cmake/Sanitizers.cmake)
# enable_sanitizers(project_options)

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" OFF)

if(ENABLE_TESTING)
  enable_testing()
  message(
    "Building Tests. Be sure to check out test/constexpr_tests for constexpr testing"
  )
  add_subdirectory(test)
endif()

set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${PLATFORM_DIR}/${BUILD_TYPE_DIR}")

add_subdirectory(lib)

add_subdirectory(src)
