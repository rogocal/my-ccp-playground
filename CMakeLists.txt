project(Constructors)
cmake_minimum_required(VERSION 3.0)


add_executable(Constructors constructors.cpp car.cpp)

target_link_libraries(${PROJECT_NAME} jsoncpp)
