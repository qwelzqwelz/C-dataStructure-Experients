#include <stdio.h>
#include <stdlib.h>
#include "libs/calculate.h"

/*
 * 顺序表 => sequence list
 * 单链表 => single chain list
 * 双链表 => double chain list
 * 单循环链表 => single cycle chain list
 * 双循环链表 => double cycle chain list
 */

int main() {
    system("chcp 65001 > nul");
    // 读入两个长整数
    seqList *num1 = largeNumRead();
    seqList *num2 = largeNumRead();
    // 新建长整数指针，用于存储运算结果
    seqList *num3 = NULL;
    int method = -1;
    int isMethodAvailable;
    do {
        // 选择三种运算中的一种
        isMethodAvailable = 1;
        printf(">请选择运算:\n1:加法\n2:减法\n3:乘法\n");
        scanf("%d", &method);
        switch (method) {
            case 1:
                num3 = largeNumPlus(num1, num2);
                break;
            case 2:
                // x-y <=> x+(-y)
                num3 = largeNumPlus(num1, largeNumReverse(num2));
                break;
            case 3:
                num3 = largeNumMultiply(num1, num2);
                break;
            default:
                printf("-- 请输入正确的数字 --\n");
                isMethodAvailable = 0;
                break;
        }
    } while (!isMethodAvailable);
    // 输出运算结果
    printf(">最终运算结果为:\n");
    largeNumPrint(num3);
    system("pause");
    return 0;
}

