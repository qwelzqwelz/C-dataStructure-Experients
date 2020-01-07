cmake_minimum_required(VERSION 3.15)
project(Exp5 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp5 main.c libs/tree.c libs/tree.h libs/queue.c libs/queue.h)