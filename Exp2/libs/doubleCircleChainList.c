//
// Created by qwelzqwelz on 2020/1/3.
//
#include <stdio.h>
#include <stdlib.h>
#include "doubleCircleChainList.h"

dccList *dccList_Init() {
    dccList *l = (dccList *) malloc(sizeof(dccList));
    l->head = (dccNode *) malloc(sizeof(dccNode));
    l->head->prior = l->head;
    l->head->next = l->head;
    l->length = 0;
    return l;
}

int dccList_InsertNode(dccList *l, int index, dccNode *n) {
    int result = 0;
    if (index < 0 || index >= l->length) {
        printf("-- 插入结点，下标越界 --\n");
    } else {
        dccNode *frontNode = l->head;
        if (index > 0) {
            frontNode = dccList_GetNode(l, index - 1);
        }
        n->next = frontNode->next;
        n->prior = frontNode;
        frontNode->next->prior = n;
        frontNode->next = n;
        l->length++;
        result = 1;
    }
    return result;
}

dccNode *dccList_InsertNum(dccList *l, int index, int num) {
    dccNode *result = NULL;
    dccNode *n = (dccNode *) malloc(sizeof(dccNode));
    n->numData = num;
    if (dccList_InsertNode(l, index, n)) {
        result = n;
    }
    return result;
}

int dccList_DeleteNode(dccList *l, int index) {
    int result = 0;
    dccNode *n = dccList_PopNode(l, index);
    if (n) {
        result = 1;
        n->next = NULL;
        n->prior = NULL;
    }
    return result;
}

dccNode *dccList_PopNode(dccList *l, int index) {
    dccNode *result = NULL;
    if (index < 0 || index >= l->length) {
        printf("-- 删除结点，下标越界 --\n");
    } else {
        dccNode *frontNode = l->head;
        if (index > 0) {
            frontNode = dccList_GetNode(l, index - 1);
        }
        result = frontNode->next;
        result->next->prior = frontNode;
        frontNode->next = result->next;
        l->length--;
    }
    return result;
}

dccNode *dccList_GetNode(dccList *l, int index) {
    dccNode *result = NULL;
    if (index < 0 || index >= l->length) {
        printf("-- 获取结点，下标越界 --\n");
    } else {
        result = l->head;
        for (int i = 0; i <= index; ++i) {
            result = result->next;
        }
    }
    return result;
}

int dccList_GetIndex(dccList *l, int num) {
    int result = -1;
    dccNode *n = l->head;
    for (int i = 0; i < l->length; ++i) {
        n = n->next;
        if (n->numData == num) {
            result = i;
            break;
        }
    }
    return result;
}

int dccList_Append(dccList *l, dccNode *n) {
    dccNode *tail = l->head->prior;
    n->next = l->head;
    n->prior = tail;
    tail->next = n;
    l->head->prior = n;
    l->length++;
    return l->length - 1;
}