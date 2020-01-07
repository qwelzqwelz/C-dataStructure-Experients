//
// Created by qwelzqwelz on 2019/12/23.
//

#ifndef EXP4_QUEUE_H
#define EXP4_QUEUE_H
#define MAX_QUEUE_LENGTH 10000
typedef struct {
    int head;
    int tail;
    char *cList;
    int length;
} queue;

queue *queueInit(int queueLength);

int queueAppend(queue *q, char c);

char queuePrePop(queue *q);

int queueIsEmpty(queue *q);

void queuePrint(queue *q);

char queueGetHead(queue * q);
#endif //EXP4_QUEUE_H
