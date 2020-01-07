//
// Created by qwelzqwelz on 2019/12/30.
//
#include <stdio.h>
#include "search.h"

// 顺序查找
long sequentialSearch(int *array, int num, long length, long *times) {
    long result = -1L;
    for (int i = 0; i < length; ++i) {
        times[0]++;
        if (num == array[i]) {
            result = i;
            break;
        }
    }
    return result;
}

// (非递归) 二分查找
long binarySearch(int *array, int num, long length, long *times) {
    long result = -1L;
    long left = 0;
    long right = length;
    long middle;
    while (right - left > 0 && result < 0) {
        middle = left + (right - left) / 2;
        times[0]++;
        if (array[middle] == num) {
            result = middle;
        } else if (num < array[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return result;
}

// 递归二分查找
long recursiveBinarySearch(int *array, int num, long left, long right, long *times) {
    long result = -1L;
    if (right - left > 0) {
        times[0]++;
        long middle = left + (right - left) / 2;
        if (array[middle] == num) {
            result = middle;
        } else if (num < array[middle]) {
            result = recursiveBinarySearch(array, num, left, middle, times);
        } else {
            result = recursiveBinarySearch(array, num, middle + 1, right, times);
        }
    }
    return result;
}