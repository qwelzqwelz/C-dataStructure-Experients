#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "libs/search.h"

#define ARRAY_LENGTH 30000L

void arrayReadFromFile(char *fileName, int *array, int length);

float testSearchTime(int *array, int length, int *testArray, int searchTimes, long *times, int method);

int main() {
    system("chcp 65001 > nul");
    // 数组初始化
    int *ascArray = (int *) malloc(sizeof(int) * ARRAY_LENGTH);
    int *randArray = (int *) malloc(sizeof(int) * ARRAY_LENGTH);
    // 读入数组长度 & 查找次数
    long length;
    long searchTimes;
    printf("请输入数组长度，最大为%ld: \n", ARRAY_LENGTH);
    scanf("%ld", &length);
    printf("请输入查找次数，最多为%ld: \n", ARRAY_LENGTH);
    scanf("%ld", &searchTimes);
    if (length > ARRAY_LENGTH) {
        printf("-- 数组超过最大长度：%ld --\n", ARRAY_LENGTH);
    } else if (searchTimes > ARRAY_LENGTH) {
        printf("-- 查找次数超过最大次数：%ld --\n", ARRAY_LENGTH);
    } else {
        // 数据初始化
        long times[1] = {0};
        float testTime;
        time_t t;
        srand((unsigned) time(&t));
        int *testArray = (int *) malloc(sizeof(int) * searchTimes);
        for (int i = 0; i < searchTimes; ++i) {
            testArray[i] = rand();
        }
        arrayReadFromFile("../data/asc_30000.txt", ascArray, ARRAY_LENGTH);
        arrayReadFromFile("../data/rand_30000.txt", randArray, ARRAY_LENGTH);
        printf("-- %d --\n", ascArray[0]);

        // 比较在有序表和无序表中进行顺序查找
        printf("-----------------------------------------------------\n"
               ">>>比较在有序表和无序表中进行顺序查找\n");
        printf("-- 数组长度：%ld, 查找次数: %ld --\n", length, searchTimes);
        testTime = testSearchTime(ascArray, length, testArray, searchTimes, times, 1);
        printf(">有序表，查找总时间：%.2f 微秒，平均比较次数：%f\n",
               testTime, times[0] / (double) searchTimes);
        testTime = testSearchTime(randArray, length, testArray, searchTimes, times, 1);
        printf(">无序表，查找总时间：%.2f 微秒，平均比较次数：%f\n",
               testTime, times[0] / (double) searchTimes);

        // 比较在同一有序表中进行顺序查找和二分查找
        printf("-----------------------------------------------------\n"
               ">>>比较在同一有序表中进行顺序查找和二分查找\n");
        testTime = testSearchTime(ascArray, length, testArray, searchTimes, times, 1);
        printf(">顺序查找，查找总时间：%.2f 微秒，平均比较次数：%f\n",
               testTime, times[0] / (double) searchTimes);
        testTime = testSearchTime(ascArray, length, testArray, searchTimes, times, 2);
        printf(">二分查找，查找总时间：%.2f 微秒，平均比较次数：%f\n",
               testTime, times[0] / (double) searchTimes);

        // 比较在同一有序表中进行非递归二分查找和递归二分查找
        printf("-----------------------------------------------------\n"
               ">>>比较在同一有序表中进行非递归二分查找和递归二分查找\n");
        testTime = testSearchTime(ascArray, length, testArray, searchTimes, times, 2);
        printf(">非递归二分查找，查找总时间：%.2f 微秒，平均比较次数：%f\n",
               testTime, times[0] / (double) searchTimes);
        testTime = testSearchTime(ascArray, length, testArray, searchTimes, times, 3);
        printf(">递归二分查找，查找总时间：%.2f 微秒，平均比较次数：%f\n",
               testTime, times[0] / (double) searchTimes);
    }
    system("pause");
    return 0;
}

void arrayReadFromFile(char *fileName, int *array, int length) {
    FILE *f = fopen(fileName, "r");
    for (int i = 0; i < length; ++i) {
        fscanf(f, "%d", &array[i]);
    }
    fclose(f);
}

float testSearchTime(int *array, int length, int *testArray, int searchTimes, long *times, int method) {
    float result;
    long index;
    times[0] = 0;
    union _LARGE_INTEGER time_start;        //开始时间
    union _LARGE_INTEGER time_over;         //结束时间
    double dqFreq;                          //计时器频率
    LARGE_INTEGER f;                        //计时器频率
    QueryPerformanceFrequency(&f);
    dqFreq = (double) f.QuadPart;
    QueryPerformanceCounter(&time_start);   //计时开始
    if (method == 1) {
        for (int i = 0; i < searchTimes; ++i) {
            sequentialSearch(array, testArray[i], length, times);
        }
    } else if (method == 2) {
        for (int i = 0; i < searchTimes; ++i) {
            binarySearch(array, testArray[i], length, times);
        }
    } else if (method == 3) {
        for (int i = 0; i < searchTimes; ++i) {
            recursiveBinarySearch(array, testArray[i], 0, length, times);
//            printf("-- testNum:%d, index:%ld, 比较次数：%ld --\n", testArray[i], index, times[0]);
        }
    }
    QueryPerformanceCounter(&time_over);    //计时结束
    // 计时结束
    result = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
    return result;
}