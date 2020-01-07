cmake_minimum_required(VERSION 3.15)
project(Exp2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Exp2 main.c libs/seqList.c libs/seqList.h libs/singleChainList.c libs/singleChainList.h libs/doubleCircleChainList.c libs/doubleCircleChainList.h libs/calculate.c libs/calculate.h)