
include_directories(${DOCTEST_INCLUDE_DIR})
include_directories(../.)
include_directories(../lib)
add_executable(TEST main.cpp test.cpp)
target_link_libraries(TEST doctest)