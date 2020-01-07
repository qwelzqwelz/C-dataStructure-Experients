cmake_minimum_required(VERSION 3.15)
project(Exp3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp3 main.c libs/stack.c libs/stack.h libs/myExpressionRead.c libs/myExperssionRead.h)