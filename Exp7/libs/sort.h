//
// Created by qwelzqwelz on 2019/12/28.
//

#ifndef EXP7_SORT_H
#define EXP7_SORT_H

#include "readAndPrint.h"

#define   SWAP(_x, _y) {int _t = _x; _x = _y; _y = _t;}

// 冒泡排序
void bubbleSort(int *array, int length);

// 选择排序
void selectSort(int *array, int length);

// 插入排序
void insertSort(int *array, int length);

// 希尔排序
void shellSort(int *array, int length);

// 归并排序
void mergeSort(int *array, int length);

void mergeSortPart(int *array, int left, int right);

// 快速排序
void quickSort(int *array, int left, int right);

// 堆排序
void heapSort(int *array, int length);

void heapify(int *array, int length, int index);

void heapInit(int *array, int length);

// 计数排序
void countSort(int *array, int length, int maxValue);

// 桶排序
void bucketSort(int *array, int length, int bucketSize);

// 基数排序
void radixSort(int *array, int length);

#endif //EXP7_SORT_H
