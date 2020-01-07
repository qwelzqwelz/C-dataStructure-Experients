//
// Created by qwelzqwelz on 2019/12/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue *queueInit(int queueLength) {
    queue *q = NULL;
    if (queueLength > MAX_QUEUE_LENGTH) {
        printf("要求的队列长度超过最大值：%d", MAX_QUEUE_LENGTH);
    } else {
        q = (queue *) malloc(sizeof(queue));
        q->head = 0;
        q->tail = 0;
        q->length = queueLength;
        q->nList = (Node **) malloc(sizeof(Node*) * queueLength);
    }
    return q;
}

int queueAppend(queue *q, Node* n) {
    int result = 0;
    if (q->tail <= q->length-1) {
        result = 1;
        q->nList[q->tail] = n;
        q->tail++;
    } else {
        printf("--队列满--\n");
    }
    return result;
}

Node* queuePrePop(queue *q) {
    Node* n = queueGetHead(q);
    if (!queueIsEmpty(q)) {
        q->head++;
    }
    return n;
}

int queueIsEmpty(queue *q) {
    int result = 0;
    if (q->head >= q->tail) {
        result = 1;
    }
    return result;
}

void queuePrint(queue *q) {
    if (queueIsEmpty(q)) {
        printf("--空队列--");
    } else {
        printf("队列元素共%d个，为：", q->tail - q->head);
        for (int i = q->head; i < q->tail; ++i) {
            printf("%c ", q->nList[i]->data);
        }
    }
    printf("\n");
}

Node* queueGetHead(queue * q){
    Node* n= NULL;
    if(queueIsEmpty(q)){
        printf("--空队列--\n");
    }else{
        n = q->nList[q->head];
    }
    return n;
}
