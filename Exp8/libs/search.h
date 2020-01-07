//
// Created by qwelzqwelz on 2019/12/30.
//

#ifndef EXP8_SEARCH_H
#define EXP8_SEARCH_H

// 顺序查找
long sequentialSearch(int *array, int num, long length, long *times);

// (非递归) 二分查找
long binarySearch(int *array, int num, long length, long *times);

// 递归二分查找
long recursiveBinarySearch(int *array, int num, long left, long right, long *times);

#endif //EXP8_SEARCH_H
