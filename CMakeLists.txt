cmake_minimum_required(VERSION 3.5)
project(MatrixMulti)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES CMatrix.h CMatrix.cpp MatrixMultiplication2.cpp)
add_executable(MatrixMulti ${SOURCE_FILES})