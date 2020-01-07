//
// Created by qwelzqwelz on 2019/12/22.
//

#ifndef EXP3_STACK_H
#define EXP3_STACK_H
// 栈-最大长度
#define MAX_STACK_LENGTH 1000

// 栈-结点
typedef struct {
    float num;
    char ch;
    int isNum;
} node;

// 栈
typedef struct {
    node *nodeList;
    int top;
    int length;
} stack;

// 栈-初始化
stack *stackInit(int stackLength);

// 栈-出栈
node *stackPop(stack *s);

// 栈-判断栈是否为空
int stackIsEmpty(stack *s);

// 栈-入栈
void stackPush(stack *s, node *n);

// 栈-读取栈顶元素(不出栈)
node *stackGetTop(stack *s);

// 栈-打印栈中的全部元素
void stackPrint(stack *s);

#endif //EXP3_STACK_H
