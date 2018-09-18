cmake_minimum_required(VERSION 3.12)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

add_executable(Matrix main.cpp Matrix.h Invalid_Matrix_Dimesions.h MatrixFactory.h)