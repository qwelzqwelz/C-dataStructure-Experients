//
// Created by qwelzqwelz on 2019/12/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack *stackInit(int stackLength) {
    stack *s = NULL;
    if (stackLength > MAX_STACK_LENGTH) {
        printf("要求的栈长度超过最大值：%d\n", MAX_STACK_LENGTH);
    } else {
        s = (stack *) malloc(sizeof(stack));
        s->top = -1;
        s->length = stackLength;
        s->cList = (char *) malloc(sizeof(char) * stackLength);
    }
    return s;
}

char stackPop(stack *s) {
    char c;
    if (!stackIsEmpty(s)) {
        c = s->cList[s->top];
        s->top--;
    }else{
        printf("--栈空--\n");
    }
    return c;
}

int stackIsEmpty(stack *s) {
    return (s->top < 0) ? 1 : 0;
}

int stackInclude(stack *s, char c) {
    int result = 0;
    for (int i = 0; i <= s->top; ++i) {
        if (s->cList[i] == c) {
            result = 1;
        }
    }
    return result;
}

void stackPush(stack *s, char c) {
    if (s->top < s->length - 1) {
        s->cList[++s->top] = c;
    } else {
        printf("--满栈--\n");
    }
}

void stackPrint(stack *s) {
    if (!stackIsEmpty(s)) {
        printf("栈中元素共%d个，为：", s->top + 1);
        for (int i = 0; i <= s->top; ++i) {
            printf("%c ", s->cList[i]);
        }
    } else {
        printf("--空栈--");
    }
    printf("\n");
}

char stackGetTop(stack *s) {
    char c;
    if (!stackIsEmpty(s)) {
        c = s->cList[s->top];
    } else {
        printf("--空栈--\n");
    }
    return c;
}