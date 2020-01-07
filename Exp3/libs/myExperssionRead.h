//
// Created by qwelzqwelz on 2019/12/22.
//

#ifndef EXP3_MYEXPERSSIONREAD_H
#define EXP3_MYEXPERSSIONREAD_H

// 使用栈存储读入的表达式
#include "stack.h"

// 表达式最大长度
#define MAX_EXPRESSION_LENGTH 1000
typedef struct {
    char *cList;
    int readPointer;
    int length;
} Expression;

// 表达式初始化
Expression *expressionInit(char *cList);

// 表达式-获取下一个结点(运算符/运算数)
node *getNextNode(Expression *exp);

// 表达式-检查输入的表达式中的字符是否是合法字符
int isCharacterAvailable(char c);

// 表达式-比较表达式优先级
int charCompare(char c1, char c2);

// 表达式-判断表达式中字符是否是运算符
int isCalChar(char c);

// 表达式-判断表达式中字符是否是运算数
int isNumChar(char c);

#endif //EXP3_MYEXPERSSIONREAD_H
