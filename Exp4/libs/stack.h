//
// Created by qwelzqwelz on 2019/12/23.
//

#ifndef EXP4_STACK_H
#define EXP4_STACK_H
#define MAX_STACK_LENGTH 1000
typedef struct {
    int top;
    char *cList;
    int length;
} stack;

stack *stackInit(int stackLength);

char stackPop(stack *s);

int stackIsEmpty(stack *s);

int stackInclude(stack *s, char c);

void stackPush(stack *s, char c);

void stackPrint(stack *s);

char stackGetTop(stack *s);

#endif //EXP4_STACK_H
