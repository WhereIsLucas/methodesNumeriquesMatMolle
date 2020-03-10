cmake_minimum_required(VERSION 3.15)
project(random_walk)

set(CMAKE_CXX_STANDARD 14)

add_executable(random_walk main.cpp leapFrog.cpp leapFrog.h)