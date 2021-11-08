
cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

project(Constructors VERSION 0.0.1 LANGUAGES C CXX)
add_executable(${PROJECT_NAME} constructors.cpp car.cpp)
#add_compile_options(${TARGET_NAME} PRIVATE -Wall -pedantic -O3)

set(CMAKE_C_FLAGS_DEBUG "-Wall -pedantic -O3")       
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -pedantic -O3")

#set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/*.cpp PROPERTIES COMPILE_FLAGS "-std=c++17 -Wall -pedantic -O3")

target_link_libraries(${PROJECT_NAME} jsoncpp)
