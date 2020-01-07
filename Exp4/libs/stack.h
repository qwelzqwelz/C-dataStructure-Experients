//
// Created by qwelzqwelz on 2019/12/23.
//

#ifndef EXP4_STACK_H
#define EXP4_STACK_H
// 栈-最大长度
#define MAX_STACK_LENGTH 1000
// 栈
typedef struct {
    int top;
    char *cList;
    int length;
} stack;

// 栈-初始化
stack *stackInit(int stackLength);

// 栈-出栈
char stackPop(stack *s);

// 栈-判断栈是否为空
int stackIsEmpty(stack *s);

// 栈-判断某个元素是否在栈中
int stackInclude(stack *s, char c);

// 栈-入栈
void stackPush(stack *s, char c);

// 栈-打印栈中所有元素
void stackPrint(stack *s);

// 栈-获取栈顶元素(不出栈)
char stackGetTop(stack *s);

#endif //EXP4_STACK_H
