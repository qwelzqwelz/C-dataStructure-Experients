cmake_minimum_required(VERSION 3.15)
project(Exp6 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp6 main.c libs/graph.c libs/graph.h libs/set.c libs/set.h)