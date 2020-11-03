cmake_minimum_required(VERSION 3.16)
project(Matrice_LU)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrice_LU main.cpp matrix.cpp matrix.h lu.cpp lu.h)