cmake_minimum_required(VERSION 3.3)
project(hellompi)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

SET(CMAKE_C_COMPILER mpicc)
SET(CMAKE_CXX_COMPILER mpicxx)

set(SOURCE_FILES main.c)
add_executable(main.c ${SOURCE_FILES})