//
// Created by qwelzqwelz on 2019/12/22.
//

#ifndef EXP3_STACK_H
#define EXP3_STACK_H
#define MAX_STACK_LENGTH 1000

typedef struct {
    float num;
    char ch;
    int isNum;
} node;

typedef struct {
    node *nodeList;
    int top;
    int length;
} stack;

stack *stackInit(int stackLength);

node *stackPop(stack *s);

int stackIsEmpty(stack *s);

void stackPush(stack *s, node *n);

node *stackPop(stack *s);

node *stackGetTop(stack *s);

void stackPrint(stack *s);

#endif //EXP3_STACK_H
