cmake_minimum_required(VERSION 3.15)
project(Exp7 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp7 main.c libs/sort.c libs/sort.h libs/readAndPrint.c libs/readAndPrint.h)