//
// Created by qwelzqwelz on 2020/1/2.
//

#include <stdio.h>
#include <stdlib.h>
#include "singleChainList.h"

scList *scList_Init() {
    scList *l = (scList *) malloc(sizeof(scList));
    l->length = 0;
    l->head = (scNode *) malloc(sizeof(scNode));
    l->head->next = NULL;
    l->tail = l->head;
    return l;
}

scNode *scList_InsertNum(scList *l, int index, int num) {
    scNode *result = NULL;
    scNode *n = (scNode *) malloc(sizeof(scNode));
    n->numData = num;
    if (scList_InsertNode(l, index, n)) {
        result = n;
    }
    return result;
}

int scList_InsertNode(scList *l, int index, scNode *n) {
    int result = 0;
    if (index < 0 || index >= l->length) {
        printf("-- 单链表插入数据，下标越界 --\n");
    } else {
        result = 1;
        scNode *nodeFind = scList_GetNode(l, index);
        n->next = nodeFind->next;
        nodeFind->next = n;
        l->length++;
    }
    return result;
}

scNode *scList_PopNode(scList *l, int index) {
    scNode *result = NULL;
    if (index < 0 || index > l->length) {
        printf("-- 单链表删除结点，下标越界 --\n");
    } else {
        scNode *frontNode = l->head;
        if (index > 0) {
            frontNode = scList_GetNode(l, index - 1);
        }
        result = frontNode->next;
        frontNode->next = result->next;
        if (index == l->length - 1) {
            l->tail = frontNode;
        }
    }
    return result;
}

int scList_DeleteNode(scList *l, int index) {
    int result = 0;
    scNode *n = scList_PopNode(l, index);
    if (n) {
        n->next = NULL;
        result = 1;
    }
    return result;
}

scNode *scList_GetNode(scList *l, int index) {
    scNode *result = NULL;
    if (index < 0 || index > l->length) {
        printf("-- 获取单链表结点，下标越界 --\n");
    } else {
        result = l->head;
        for (int i = 0; i <= index; ++i) {
            result = result->next;
        }
    }
    return result;
}

int scList_GetIndex(scList *l, int num) {
    int result = -1;
    scNode *node = l->head;
    for (int i = 0; i < l->length; ++i) {
        node = node->next;
        if (node && node->numData == num) {
            result = i;
            break;
        }
    }
    return result;
}

int scList_AppendNode(scList *l, scNode *n) {
    n->next = NULL;
    l->tail->next = n;
    l->length++;
    return l->length - 1;
}

int scList_AppendByNumData(scList *l, int num) {
    scNode *n = (scNode *) malloc(sizeof(scNode));
    n->next = NULL;
    n->numData = num;
    l->tail->next = n;
    l->length++;
    return l->length - 1;
}