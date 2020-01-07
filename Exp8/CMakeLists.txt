cmake_minimum_required(VERSION 3.15)
project(Exp8 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp8 main.c libs/search.c libs/search.h)