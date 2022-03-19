cmake_minimum_required(VERSION 3.1)
project(TEST)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_subdirectory(${LIB_DIR}/doctest)

add_executable(TEST test.cpp)

target_include_directories(TEST PRIVATE ${LIB_DIR})
target_include_directories(TEST PRIVATE ${FILE_DIR})
target_include_directories(TEST PRIVATE ${DOCTEST_INCLUDE_DIR})

target_link_libraries(TEST doctest)