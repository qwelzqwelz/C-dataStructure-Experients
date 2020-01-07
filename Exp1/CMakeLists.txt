cmake_minimum_required(VERSION 3.15)
project(Exp1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp1 main.c libs/fileModule.c libs/fileModule.h libs/randomModule.c libs/randomModule.h libs/minMax.h)