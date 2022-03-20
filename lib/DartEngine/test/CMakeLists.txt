cmake_minimum_required(VERSION 3.1)
project(TEST)

# Need to install on linux doctest-dev
find_package(doctest REQUIRED)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/../..)

add_executable(TEST test.cpp)

target_include_directories(TEST PRIVATE ${LIB_DIR})
target_include_directories(TEST PRIVATE ${DOCTEST_INCLUDE_DIR})

target_link_libraries(TEST PRIVATE doctest::doctest)