//
// Created by qwelzqwelz on 2019/12/28.
//
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// 冒泡排序
void bubbleSort(int *array, int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i; j < length; ++j) {
            if (array[i] > array[j]) {
                SWAP(array[i], array[j]);
            }
        }
    }
}

// 选择排序
void selectSort(int *array, int length) {
    for (int i = 0; i < length - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < length; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        SWAP(array[i], array[minIndex]);
    }
}

// 插入排序
void insertSort(int *array, int length) {
    int sortLength = 1;
    int temp;
    while (sortLength < length) {
        temp = array[sortLength];
        for (int i = 0; i < sortLength; ++i) {
            if (temp > array[i]) {
                continue;
            } else {
                for (int j = sortLength; j > i; --j) {
                    array[j] = array[j - 1];
                }
                array[i] = temp;
                break;
            }
        }
        sortLength++;
    }
}

// 希尔排序
void shellSort(int *array, int length) {
    int step = length / 2;
    int temp;
    while (step >= 1) {
        // 分为 step 组
        for (int i = 0; i < step; ++i) {
            // 小组内直接插入排序，步长step
            for (int j = 1; j * step + i < length; ++j) {
                temp = array[j * step + i];
                for (int k = 0; k < j; ++k) {
                    if (temp > array[k * step + i]) {
                        continue;
                    } else {
                        for (int l = j; l > k; --l) {
                            array[l * step + i] = array[l * step + i - step];
                        }
                        array[k * step + i] = temp;
                        break;
                    }
                }
            }
        }
        step /= 2;
    }
}

// 归并排序
void mergeSort(int *array, int length) {
    mergeSortPart(array, 0, length);
}

void mergeSortPart(int *array, int left, int right) {
    if (right - left <= 1) {
        return;
    } else if (right - left == 2) {
        if (array[left] > array[left + 1]) {
            SWAP(array[left], array[left + 1])
        }
    } else {
        int middle = left + (right - left) / 2;
        mergeSortPart(array, left, middle);
        mergeSortPart(array, middle, right);
        int *arrayLeft = (int *) malloc(sizeof(int) * (middle - left));
        for (int i = 0; i < middle - left; ++i) {
            arrayLeft[i] = array[left + i];
        }
        int p1 = 0;
        int p2 = middle;
        for (int j = left; j < right; ++j) {
            if ((p1 > middle - left - 1 || arrayLeft[p1] >= array[p2]) && p2 < right) {
                array[j] = array[p2];
                p2++;
            } else {
                array[j] = arrayLeft[p1];
                p1++;
            }
        }
    }
}

// 快速排序
void quickSort(int *array, int left, int right) {
    if (right - left <= 1) {
        return;
    } else {
        // 以 array[left] 为基准
        int middleIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (array[i] < array[left]) {
                middleIndex++;
                SWAP(array[i], array[middleIndex]);
            }
        }
        SWAP(array[left], array[middleIndex]);
        quickSort(array, left, middleIndex);
        quickSort(array, middleIndex + 1, right);
    }
}

// 堆排序-大顶堆
void heapSort(int *array, int length) {
    heapInit(array, length);
    for (; length >= 2; --length) {
        SWAP(array[0], array[length - 1]);
        heapify(array, length - 1, 0);
    }
}

void heapify(int *array, int length, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    if (left >= length) {
        return;
    } else if (right >= length) {
        if (array[left] > array[index]) {
            SWAP(array[left], array[index]);
        }
    } else {
        if (array[index] < array[left] || array[index] < array[right]) {
            if (array[left] < array[right]) {
                SWAP(array[right], array[index]);
                heapify(array, length, right);
            } else {
                SWAP(array[left], array[index]);
                heapify(array, length, left);
            }

        }
    }
}

void heapInit(int *array, int length) {
    for (int i = length / 2; i >= 0; --i) {
        heapify(array, length, i);
    }
}

// 计数排序
void countSort(int *array, int length, int maxValue) {
    int *countArray = (int *) calloc(maxValue + 1, sizeof(int));
    for (int i = 0; i < length; ++i) {
        countArray[array[i]]++;
    }
    int index = 0;
    for (int j = 0; j < maxValue + 1; ++j) {
        for (int i = 0; i < countArray[j]; ++i) {
            array[index] = j;
            index++;
        }
    }
}

// 桶排序
void bucketSort(int *array, int length, int bucketSize) {
    if (length <= 0) {
        return;
    }
    // 求取最大最小值
    int max = array[0];
    int min = array[0];
    for (int i = 0; i < length; ++i) {
        if (array[i] < min) {
            min = array[i];
        } else if (array[i] > max) {
            max = array[i];
        }
    }
    // 分组
    int **buckets = (int **) malloc(sizeof(int *) * bucketSize);
    for (int l = 0; l < bucketSize; ++l) {
        buckets[l] = (int *) malloc(sizeof(int) * length);
    }
    int step = (max - (min - 1) + 1) / bucketSize + 1;
    int *lengthArray = (int *) calloc(bucketSize, sizeof(int));
    int index = 0;
    for (int j = 0; j < length; ++j) {
        index = (array[j] - min) / step;
        buckets[index][lengthArray[index]] = array[j];
        lengthArray[index]++;
    }
    // 分组排序
    for (int k = 0; k < bucketSize; ++k) {
        quickSort(buckets[k], 0, lengthArray[k]);
    }
    // 合并
    int arrayIndex = 0;
    for (int i = 0; i < bucketSize; ++i) {
        for (int j = 0; j < lengthArray[i]; ++j) {
            array[arrayIndex] = buckets[i][j];
            arrayIndex++;
        }
    }
}

// 基数排序
void radixSort(int *array, int length) {
    if (length <= 0) {
        return;
    }
    const int RADIX = 10;
    // 求取最大值
    int maxValue = array[0];
    for (int j = 0; j < length; ++j) {
        if (maxValue < array[j]) {
            maxValue = array[j];
        }
    }
    // 数组&变量 初始化
    int lengthArray[RADIX];
    int **base = (int **) malloc(sizeof(int *) * RADIX);
    for (int k = 0; k < RADIX; ++k) {
        base[k] = (int *) malloc(sizeof(int) * length);
    }
    int devNum = 1;
    int index;
    // 多轮基数排序
    for (; maxValue > 0; maxValue /= RADIX) {
        devNum *= 10;
        // 长度数组置零
        for (int i = 0; i < RADIX; ++i) {
            lengthArray[i] = 0;
        }
        // 重新按照基数分组
        for (int k = 0; k < length; ++k) {
            index = (array[k] % devNum) / (devNum / 10);
            base[index][lengthArray[index]] = array[k];
            lengthArray[index]++;
        }
        // 将分组数据重新写回大数组
        index = 0;
        for (int j = 0; j < RADIX; ++j) {
            for (int i = 0; i < lengthArray[j]; ++i) {
                array[index] = base[j][i];
                index++;
            }
        }
    }
}