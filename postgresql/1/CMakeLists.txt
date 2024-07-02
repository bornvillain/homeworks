cmake_minimum_required(VERSION 3.28)
project(db)

add_subdirectory(libpqxx libpqxx-build)

add_executable(db main.cpp)
target_compile_features(db PRIVATE cxx_std_17)

target_link_libraries(db PRIVATE pqxx)