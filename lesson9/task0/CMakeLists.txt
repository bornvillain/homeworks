cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
project(Greeter)
add_library(GreeterStaticLib STATIC Greeter.cpp Greeter.h)
add_executable(GreeterExe main.cpp)
target_link_libraries(GreeterExe GreeterStaticLib)
