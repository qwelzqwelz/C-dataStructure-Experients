//
// Created by qwelzqwelz on 2019/12/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *stackInit(int stackLength) {
    stack *s = (stack *) malloc(sizeof(stack));
    if (stackLength > MAX_STACK_LENGTH) {
        printf("要求的初始化栈长度超过最大值：%d", MAX_STACK_LENGTH);
    } else {
        s->nodeList = (node *) malloc(sizeof(node) * stackLength);
        s->top = -1;
        s->length = stackLength;
    }
    return s;
}

node *stackPop(stack *s) {
    node *n = stackGetTop(s);
    if (n) {
        s->top--;
    }
    return n;
}

node *stackGetTop(stack *s) {
    node *n = NULL;
    if (!stackIsEmpty(s)) {
        n = &(s->nodeList[s->top]);
    }
    return n;
}

int stackIsEmpty(stack *s) {
    return ((s->top < 0) ? 1 : 0);
}

void stackPush(stack *s, node *n) {
    if (s->top >= s->length) {
        printf("--栈满--\n");
    } else {
        s->top++;
        s->nodeList[s->top] = *n;
    }
}

void stackPrint(stack *s) {
    if (stackIsEmpty(s)) {
        printf("---空栈---");
    } else {
        printf("栈中元素数：%d, 为：", s->top+1);
        for (int i = 0; i <=s->top; ++i) {
            if (s->nodeList[i].isNum) {
                printf("%f ", s->nodeList[i].num);
            } else {
                printf("%c ", s->nodeList[i].ch);
            }
        }
    }
    printf("\n");
}

