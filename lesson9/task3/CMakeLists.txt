cmake_minimum_required(VERSION 3.27)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FigureDynamicLib SHARED figure.cpp triangle.cpp right_triangle.cpp isosceles_triangle.cpp
        equilateral_triangle.cpp quadrilateral.cpp rectangle.cpp square.cpp parallelogram.cpp rhombus.cpp)

add_executable(test main.cpp)

target_link_libraries(test FigureDynamicLib)
