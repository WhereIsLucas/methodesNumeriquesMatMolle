cmake_minimum_required(VERSION 3.15)
project(cell_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(cell_system main.cpp classes/Particle.cpp classes/Particle.h classes/Cell.cpp classes/Cell.h classes/CellSystem.cpp classes/CellSystem.h)