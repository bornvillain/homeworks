cmake_minimum_required(VERSION 3.27)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp figure.cpp triangle.cpp right_triangle.cpp isosceles_triangle.cpp equilateral_triangle.cpp
               quadrilateral.cpp rectangle.cpp square.cpp parallelogram.cpp rhombus.cpp)
