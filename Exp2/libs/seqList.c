//
// Created by qwelzqwelz on 2020/1/2.
//

#include <stdio.h>
#include <stdlib.h>
#include "seqList.h"

seqList *seqList_Init(int maxLength) {
    seqList *l = NULL;
    if (maxLength > MAX_LIST_LENGTH) {
        printf("-- 超过链表的初始化最大长度：%d --\n", MAX_LIST_LENGTH);
    } else {
        l = (seqList *) malloc(sizeof(int) * maxLength);
        l->maxLength = maxLength;
        l->dataList = (int *) malloc(sizeof(int) * l->maxLength);
        l->length = 0;
    }
    return l;
}

int seqList_InsertNode(seqList *l, int index, int data) {
    int result = 0;
    if (index < 0 || index > l->length) {
        printf("-- 下标越界 --\n");
    } else if (l->length >= l->maxLength) {
        printf("-- 链表已满 --\n");
    } else {
        for (int i = l->length; i > index; --i) {
            l->dataList[i] = l->dataList[i - 1];
        }
        l->dataList[index] = data;
        l->length++;
        result = 1;
    }
    return result;
}

int seqList_DeleteNode(seqList *l, int index) {
    int result = 0;
    if (index < 0 || index > l->length) {
        printf("-- 下标越界 --\n");
    } else {
        result = l->dataList[index];
        for (int i = index; i < l->length - 1; ++i) {
            l->dataList[i] = l->dataList[i + 1];
        }
        l->length--;
    }
    return result;
}

int seqList_Set(seqList *l, int index, int data) {
    int result = 0;
    if (index < 0 || index > l->length) {
        printf("-- 下标越界 --\n");
    } else {
        result = 1;
        l->dataList[index] = data;
    }
    return result;
}

int seqList_Get(seqList *l, int index) {

    int result = 0;
    if (index < 0 || index > l->length) {
        printf("-- 下标越界 --\n");
    } else {
        result = l->dataList[index];
    }
    return result;
}

int seqList_GetIndex(seqList *l, int data) {
    int result = -1;
    for (int i = 0; i < l->length; ++i) {
        if (l->dataList[i] == data) {
            result = i;
            break;
        }
    }
    return result;
}

int seqList_Append(seqList *l, int data) {
    int result = 0;
    if (l->length >= l->maxLength) {
        printf("-- 链表已满 --\n");
    } else {
        result = 1;
        l->dataList[l->length] = data;
        l->length++;
    }
    return result;
}

void seqList_ClearAll(seqList *l) {
    l->length = 0;
}

int seqList_Prepend(seqList *l, int data) {
    return seqList_InsertNode(l, 0, data);
}