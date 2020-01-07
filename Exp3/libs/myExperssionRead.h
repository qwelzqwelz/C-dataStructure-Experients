//
// Created by qwelzqwelz on 2019/12/22.
//

#ifndef EXP3_MYEXPERSSIONREAD_H
#define EXP3_MYEXPERSSIONREAD_H

#include "stack.h"

#define MAX_EXPRESSION_LENGTH 1000
typedef struct {
    char *cList;
    int readPointer;
    int length;
} Expression;

Expression *expressionInit(char *cList);

node *getNextNode(Expression *exp);

int isCharacterAvailable(char c);

int charCompare(char c1, char c2);

int isCalChar(char c);

int isNumChar(char c);

#endif //EXP3_MYEXPERSSIONREAD_H
