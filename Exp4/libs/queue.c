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
        q->cList = (char *) malloc(sizeof(char) * queueLength);
    }
    return q;
}

int queueAppend(queue *q, char c) {
    int result = 0;
    if (q->tail <= q->length-1) {
        result = 1;
        q->cList[q->tail] = c;
        q->tail++;
    } else {
        printf("--队列满--\n");
    }
    return result;
}

char queuePrePop(queue *q) {
    char c = queueGetHead(q);
    if (!queueIsEmpty(q)) {
        q->head++;
    }
    return c;
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
            printf("%c ", q->cList[i]);
        }
    }
    printf("\n");
}

char queueGetHead(queue * q){
    char c = '_';
    if(queueIsEmpty(q)){
        printf("--空队列--\n");
    }else{
        c = q->cList[q->head];
    }
    return c;
}
