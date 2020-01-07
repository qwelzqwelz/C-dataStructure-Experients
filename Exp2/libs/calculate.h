//
// Created by qwelzqwelz on 2020/1/3.
//

#ifndef EXP2_CALCULATE_H
#define EXP2_CALCULATE_H

// 使用顺序表实现
#include "seqList.h"

// 允许的长整数最大长度
#define MAX_NUM_LENGTH 10000

// 从标准输入读取长整数(允许负数)
seqList *largeNumRead();

// 长整数相加
seqList *largeNumPlus(seqList *num1, seqList *num2);

// 长整数相减
seqList *largeNumMinus(seqList *num1, seqList *num2);

// 长整数相乘
seqList *largeNumMultiply(seqList *num1, seqList *num2);

// 打印长整数
void largeNumPrint(seqList *num);

// 取长整数的相反数
seqList *largeNumReverse(seqList *num);

// 长整数与个位数相加
seqList *largeNumSingleMul(seqList *num, int x);

#endif //EXP2_CALCULATE_H
