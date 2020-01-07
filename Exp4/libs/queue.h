//
// Created by qwelzqwelz on 2019/12/23.
//

#ifndef EXP4_QUEUE_H
#define EXP4_QUEUE_H
// 队列-最大长度
#define MAX_QUEUE_LENGTH 10000
// 队列
typedef struct {
    int head;
    int tail;
    char *cList;
    int length;
} queue;

// 队列-初始化
queue *queueInit(int queueLength);

// 队列-入队
int queueAppend(queue *q, char c);

// 队列-出队
char queuePrePop(queue *q);

// 队列-判断队列是否为空
int queueIsEmpty(queue *q);

// 队列-打印队列
void queuePrint(queue *q);

// 队列-读取队列的头结点(不出队)
char queueGetHead(queue *q);

#endif //EXP4_QUEUE_H
