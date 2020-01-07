//
// Created by qwelzqwelz on 2019/12/28.
//
#include <stdio.h>
#include "readAndPrint.h"

// 打印整数数组
void arrayPrint(int *array, int length) {
    printf("--------------------------------------------------\n");
    printf("数组长度：%d，元素为：\n", length);
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n--------------------------------------------------\n");
}

// 从文件读取数据，存储到给定的数组中
void arrayReadFromFile(char *fileName, int *array, int length) {
    FILE *f = fopen(fileName, "r");
    for (int i = 0; i < length; ++i) {
        fscanf(f, "%d", &array[i]);
    }
    fclose(f);
}