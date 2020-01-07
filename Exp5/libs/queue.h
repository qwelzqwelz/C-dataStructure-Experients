//
// Created by qwelzqwelz on 2019/12/23.
//

#ifndef EXP4_QUEUE_H
#define EXP4_QUEUE_H
#define MAX_QUEUE_LENGTH 10000

#include "tree.h"

typedef struct {
    int head;
    int tail;
    Node **nList;
    int length;
} queue;

queue *queueInit(int queueLength);

int queueAppend(queue *q, Node *n);

Node* queuePrePop(queue *q);

int queueIsEmpty(queue *q);

void queuePrint(queue *q);

Node* queueGetHead(queue *q);

#endif //EXP4_QUEUE_H
