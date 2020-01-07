//
// Created by qwelzqwelz on 2019/12/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

Set *setInit(int setSize) {
    Set *s = (Set *) malloc(sizeof(Set));
    s->nList = (Node **) malloc(sizeof(Node *) * setSize);
    s->maxSize = setSize;
    s->size = 0;
    return s;
}

int setHas(Set *s, Node *n) {
    int result = 0;
    for (int i = 0; i < s->size; ++i) {
        if (n == s->nList[i]) {
            result = 1;
            break;
        }
    }
    return result;
}

int setAdd(Set *s, Node *n) {
    int result = 1;
    if (setHas(s, n)) {
        result = 0;
    } else if (s->size >= s->maxSize) {
        result = 0;
        printf("--集合已满--\n");
    } else {
        s->nList[s->size] = n;
        s->size++;
    }
    return result;
}

int setDelete(Set *s, Node *n) {
    int result = 0;
    for (int i = 0; i < s->size; ++i) {
        if (n == s->nList[i]) {
            for (int j = i; j < s->size - 1; ++j) {
                s->nList[j] = s->nList[j + 1];
            }
            s->nList[s->size - 1] = NULL;
            s->size--;
            result = 1;
            break;
        }
    }
    if(!result){
        printf("--集合中不存在指定元素，删除失败--\n");
    }
    return result;
}

Set *setCopy(Set *s) {
    Set *result = setInit(s->maxSize);
    for (int i = 0; i < s->size; ++i) {
        setAdd(result, s->nList[i]);
    }
    return result;
}

int setIsEmpty(Set *s) {
    return (s->size <= 0) ? 1 : 0;
}

Node *setGetNodeByData(Set *s, char *name) {
    Node *result = NULL;
    for (int i = 0; i < s->size; ++i) {
//        printf("--compare-- s1:%s , s2:%s--\n", name, s->nList[i]->name);
        if (strcmp(name, s->nList[i]->name) == 0) {
            result = s->nList[i];
            break;
        }
    }
    return result;
}

void setPrint(Set *s) {
    printf("**************************************\n");
//    printf("集合的元素数量为：%d, 为：", s->size);
//    for (int i = 0; i < s->size; ++i) {
//        printf("%p ", s->nList[i]->name);
//    }
//    printf("\n");
    printf("集合的元素数量为：%d, 为：", s->size);
    for (int i = 0; i < s->size; ++i) {
        printf("%s ", s->nList[i]->name);
    }
    printf("\n");
    printf("**************************************\n");
}
