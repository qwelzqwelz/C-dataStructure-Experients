#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "libs/sort.h"
#include "libs/readAndPrint.h"

#define MAX_FILE_NAME_LENGTH 200
#define MAX_VALUE 2<<15

double sortTest(char *dataType, int dataNum, int method);

void selectSortMethod(int *array, int length, int method);

int main() {
    system("chcp 65001 > nul");
    char *methodDict[] = {
            "冒泡排序",
            "选择排序",
            "插入排序",
            "希尔排序",
            "归并排序",
            "快速排序",
            "堆排序",
            "计数排序",
            "桶排序",
            "基数排序",
    };
    char *dataType[] = {"asc", "desc", "rand"};
    int num[] = {20, 200, 2000};
    double time[3][3][10] = {0};
    for (int i = 0; i < sizeof(dataType) / sizeof(char *); ++i) {
        for (int j = 0; j < sizeof(num) / sizeof(int); ++j) {
            printf("-------------------------------------------------\n");
            printf("-- 数据量：%d, 数据类型：%s --\n\n", num[j], dataType[i]);
            for (int k = 0; k < 10; ++k) {
                time[i][j][k] = sortTest(dataType[i], num[j], k + 1);
                printf(">%s \t耗时：%.2f 微秒 \n", methodDict[k], time[i][j][k]);
            }
            printf("-------------------------------------------------\n");
        }
    }
    system("pause");
    return 0;
}

double sortTest(char *dataType, int dataNum, int method) {
    double result;
    char *fileName = (char *) malloc(sizeof(char) * MAX_FILE_NAME_LENGTH);
    sprintf(fileName, "%s%s%s%d%s", "../data/", dataType, "_", dataNum, ".txt");
    int *array = (int *) malloc(sizeof(int) * dataNum);
    arrayReadFromFile(fileName, array, dataNum);
    // 计时开始
    union _LARGE_INTEGER time_start;        //开始时间
    union _LARGE_INTEGER time_over;         //结束时间
    double dqFreq;                          //计时器频率
    LARGE_INTEGER f;                        //计时器频率
    QueryPerformanceFrequency(&f);
    dqFreq = (double) f.QuadPart;
    QueryPerformanceCounter(&time_start);   //计时开始
    selectSortMethod(array, dataNum, method);
    QueryPerformanceCounter(&time_over);    //计时结束
    // 计时结束
    result = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
    return result;
}

void selectSortMethod(int *array, int length, int method) {
    switch (method) {
// 冒泡排序
        case 1:
            bubbleSort(array, length);
            break;
// 选择排序
        case 2:
            selectSort(array, length);
            break;
// 插入排序
        case 3:
            insertSort(array, length);
            break;
// 希尔排序
        case 4:
            shellSort(array, length);
            break;
// 归并排序
        case 5:
            mergeSort(array, length);
            break;
// 快速排序
        case 6:
            quickSort(array, 0, length);
            break;
// 堆排序
        case 7:
            heapSort(array, length);
            break;
// 计数排序
        case 8:
            countSort(array, length, MAX_VALUE);
            break;
// 桶排序
        case 9:
            bucketSort(array, length, 10);
            break;
// 基数排序
        case 10:
            radixSort(array, length);
            break;
// 错误的方法序号
        default:
            printf("-- 请输入1~10选择排序算法 --\n");
    }
}
