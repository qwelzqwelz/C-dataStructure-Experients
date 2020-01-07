//
// Created by qwelzqwelz on 2019/12/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "myExperssionRead.h"

Expression *expressionInit(char *cList) {
    Expression *exp = NULL;
    int expLength = 0;
    char c = '*';
    while (c != '#' && expLength <= MAX_EXPRESSION_LENGTH) {
        c = cList[expLength];
        expLength++;
    }
    if (expLength > MAX_EXPRESSION_LENGTH) {
        printf("表达式错误");
    } else {
        for (int i = 0; i < expLength - 1; ++i) {
            if (!isCharacterAvailable(cList[i])) {
                expLength = 0;
            }
        }
        if (expLength <= 0) {
            printf("表达式错误");
        } else {
            exp = (Expression *) malloc(sizeof(Expression));
            exp->length = expLength;
            exp->cList = cList;
            exp->cList[exp->length] = '#';
            exp->readPointer = 0;
        }
    }
    return exp;
}

node *getNextNode(Expression *exp) {
    node *n = (node *) malloc(sizeof(node));
    if (exp->readPointer >= exp->length) {
        n = NULL;
    } else if (isNumChar(exp->cList[exp->readPointer])) {
        n->isNum = 1;
        sscanf(&(exp->cList[exp->readPointer]), "%f", &n->num);
        exp->readPointer++;
        while (isNumChar(exp->cList[exp->readPointer])) {
            exp->readPointer++;
        }
    } else {
        n->ch = exp->cList[exp->readPointer];
        n->isNum = 0;
        exp->readPointer++;
    }
    return n;
}

int isCharacterAvailable(char c) {
    int result = 0;
    char cList[] = {'+', '-', '*', '/', '.', '(', ')'};
    if (c >= '0' && c <= '9') {
        result = 1;
    } else {
        for (int i = 0; i < sizeof(cList) / sizeof(char); ++i) {
            if (c == cList[i]) {
                result = 1;
            }
        }
    }
    return result;
}

int charCompare(char c1, char c2) {
    int result = 0;
    if ((c1 == '+' || c1 == '-') && (c2 == '+' || c2 == '-')) {
        result = 0;
    } else if ((c1 == '*' || c1 == '/') && (c2 == '*' || c2 == '/')) {
        result = 0;
    } else if ((c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-')) {
        result = 1;
    } else if ((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/')) {
        result = -1;
    }
    return result;
}

int isCalChar(char c) {
    int result = 0;
    char cList[] = {'+', '-', '*', '/'};
    for (int i = 0; i < sizeof(cList) / sizeof(char); ++i) {
        if (cList[i] == c) {
            result = 1;
        }
    }
    return result;
}

int isNumChar(char c) {
    int result = 0;
    if ((c >= '0' && c <= '9') || c == '.') {
        result = 1;
    }
    return result;
}
