cmake_minimum_required(VERSION 3.15)
project(Exp4 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp4 main.c libs/stack.c libs/stack.h libs/queue.h libs/queue.c)