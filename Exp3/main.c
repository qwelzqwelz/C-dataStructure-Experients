#include <stdio.h>
#include <stdlib.h>
#include "libs/stack.h"
#include "libs/myExperssionRead.h"

void toRPN(stack *S1, stack *S2, Expression *exp);

float calRPN(stack *S1, stack *S2);

float numCalculate(float num1, float num2, char c);

int main() {
    system("chcp 65001 > nul");
    printf("请输入中缀表达式(#结尾)：\n");
    char *cList = (char *) malloc(sizeof(char) * MAX_EXPRESSION_LENGTH);
    scanf("%s", cList);
    Expression *exp = expressionInit(cList);
    stack *S1 = stackInit(exp->length);
    stack *S2 = stackInit(exp->length);
    toRPN(S1, S2, exp);
    float calResult = calRPN(S2, S1);
    printf("-------------------------------------\n表达式的运算结果为：%f", calResult);
    system("pause");
    return 0;
}

void toRPN(stack *S1, stack *S2, Expression *exp) {
    node *n = getNextNode(exp);
    while (n) {
        printf("-------------------------------------\n");
        if (n->isNum) {
            printf("读取结果为，操作数：%f \n", n->num);
        } else {
            printf("读取结果为，运算符：%c \n", n->ch);
        }

        if (n->isNum) {
            stackPush(S2, n);
        } else {
            if (n->ch == '#') {
                break;
            } else if (isCalChar(n->ch)) {
                while (!stackIsEmpty(S1) && isCalChar(stackGetTop(S1)->ch) &&
                       charCompare(stackGetTop(S1)->ch, n->ch) >= 0) {
                    stackPush(S2, stackPop(S1));
                }
                stackPush(S1, n);
            } else if (n->ch == '(') {
                stackPush(S1, n);
            } else if (n->ch == ')') {
                do {
                    if (stackIsEmpty(S1)) {
                        printf("缺少'('\n");
                        break;
                    } else {
                        if (stackGetTop(S1)->ch != '(') {
                            stackPush(S2, stackPop(S1));
                        } else {
                            stackPop(S1);
                            break;
                        }
                    }
                } while (1);
            }
        }
        printf("栈S1: ");
        stackPrint(S1);
        printf("栈S2: ");
        stackPrint(S2);
        printf("-------------------------------------\n");
        n = getNextNode(exp);
    }
    while (!stackIsEmpty(S1)) {
        stackPush(S2, stackPop(S1));
    }
    printf("逆波兰式转换完成：\n");
    stackPrint(S2);
}

float calRPN(stack *S1, stack *S2) {
    // S1 存储逆波兰式（后缀表达式）, S2 为空栈
    float result = 0.0;
    // Step1: 将逆波兰式入栈S2逆置，方便读取
    while (!stackIsEmpty(S1)) {
        stackPush(S2, stackPop(S1));
    }
    // Step2: 逐个读取逆波兰式，出栈S2
    node *numNode1;
    node *numNode2;
    node *n = NULL;
    do {
        printf("-------------------------------------\n");
        printf("栈S1: ");
        stackPrint(S1);
        printf("栈S2: ");
        stackPrint(S2);
        printf("-------------------------------------\n");
        n = stackPop(S2);
        if (n->isNum) {
            stackPush(S1, n);
        } else {
            numNode2 = stackPop(S1);
            if (stackIsEmpty(S1)) {
                printf("存在多余运算符，缺少运算数。\n");
                break;
            } else {
                numNode1 = stackPop(S1);
                if (n->ch == '/' && numNode2 == 0) {
                    printf("除数不能为0。\n");
                    break;
                }
                numNode1->num = numCalculate(numNode1->num, numNode2->num, n->ch);
                stackPush(S1, numNode1);
            }
        }
    } while (!stackIsEmpty(S2));
    if (stackIsEmpty(S1)) {
        printf("运算出错。\n");
    } else {
        n = stackPop(S1);
        if (!stackIsEmpty(S1)) {
            printf("存在多余运算数。");
        } else {
            result = n->num;
        }
    }
    return result;
}

float numCalculate(float num1, float num2, char c) {
    float result = 0;
    if (c == '+') {
        result = num1 + num2;
    } else if (c == '-') {
        result = num1 - num2;
    } else if (c == '*') {
        result = num1 * num2;
    } else if (c == '/') {
        result = num1 / num2;
    }
    return result;
}