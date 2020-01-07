//
// Created by qwelzqwelz on 2019/12/28.
//
#include <stdio.h>
#include "readAndPrint.h"

void arrayPrint(int *array, int length) {
    printf("--------------------------------------------------\n");
    printf("数组长度：%d，元素为：\n", length);
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n--------------------------------------------------\n");
}

void arrayReadFromFile(char *fileName, int *array, int length) {
    FILE *f = fopen(fileName, "r");
    for (int i = 0; i < length; ++i) {
        fscanf(f, "%d", &array[i]);
    }
    fclose(f);
}