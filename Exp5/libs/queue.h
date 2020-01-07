//
// Created by qwelzqwelz on 2019/12/23.
//

#ifndef EXP4_QUEUE_H
#define EXP4_QUEUE_H
// 队列-最大长度
#define MAX_QUEUE_LENGTH 10000

// 队列-使用树的结点
#include "tree.h"

// 队列
typedef struct {
    int head;
    int tail;
    Node **nList;
    int length;
} queue;

// 队列-初始化
queue *queueInit(int queueLength);

// 队列-入队
int queueAppend(queue *q, Node *n);

// 队列-出队
Node *queuePrePop(queue *q);

// 队列-判断队列是否为空
int queueIsEmpty(queue *q);

// 队列-打印队列中的全部元素
void queuePrint(queue *q);

// 队列-读取队列的头元素(不出队)
Node *queueGetHead(queue *q);

#endif //EXP4_QUEUE_H
