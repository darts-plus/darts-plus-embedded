cmake_minimum_required(VERSION 3.1)
add_subdirectory(lib/doctest)
add_subdirectory(test)

include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(AAA main.cpp)
