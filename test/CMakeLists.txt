cmake_minimum_required(VERSION 3.12)
add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES TestMatrix.cpp)
add_executable(TestMatrix ${TEST_SOURCE_FILES})
target_link_libraries(TestMatrix gtest gtest_main core)