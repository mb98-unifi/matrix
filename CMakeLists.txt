cmake_minimum_required(VERSION 3.12)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)

set(SOURCE_FILES Matrix.h Invalid_Matrix_Dimesions.h MatrixFactory.h Matrix.cpp)
add_executable(Matrix main.cpp)
add_library(core ${SOURCE_FILES})
set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Matrix core)