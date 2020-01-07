//
// Created by qwelzqwelz on 2019/12/30.
//

#ifndef EXP8_SEARCH_H
#define EXP8_SEARCH_H

long sequentialSearch(int *array, int num, long length, long *times);

long binarySearch(int *array, int num, long length, long *times);

long recursiveBinarySearch(int *array, int num, long left, long right, long *times);

#endif //EXP8_SEARCH_H
