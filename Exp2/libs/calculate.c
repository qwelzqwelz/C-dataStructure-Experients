//
// Created by qwelzqwelz on 2020/1/3.
//
#include <stdio.h>
#include "calculate.h"

seqList *largeNumRead() {
    seqList *result = seqList_Init(MAX_NUM_LENGTH);
    printf("请输入长整数，回车结束(允许带负号):\n");
    char c;
    int isNegative = 0;
    int isRead = 0;
    while (!isRead) {
        do {
            c = (char) getchar();
            if (c == '-') {
                if (!(!isNegative && result->length == 0)) {
                    break;
                } else {
                    isNegative = 1;
                    seqList_Append(result, -1);
                }
            } else if (c >= '0' && c <= '9') {
                seqList_Append(result, c - '0');
            } else if (c == '\n') {
                if (!isNegative) {
                    if (result->length > 0) {
                        isRead = 1;
                        break;
                    } else {
                        continue;
                    }
                } else {
                    if (result->length > 1) {
                        isRead = 1;
                    }
                    break;
                }
            } else {
                break;
            }
        } while (1);
        if (!isRead) {
            while (getchar() != '\n') {}
            printf(">输入格式不正确，请重新输入：\n");
            seqList_ClearAll(result);
            isNegative = 0;
        }
    }
    return result;
}

seqList *largeNumPlus(seqList *num1, seqList *num2) {
    seqList *result;
    if (seqList_Get(num1, 0) < 0 && seqList_Get(num2, 0) < 0) {
        result = largeNumPlus(largeNumReverse(num1), largeNumReverse(num2));
        result = largeNumReverse(result);
    } else if (seqList_Get(num1, 0) < 0 && seqList_Get(num2, 0) > 0) {
        result = largeNumMinus(num2, largeNumReverse(num1));
    } else if (seqList_Get(num1, 0) > 0 && seqList_Get(num2, 0) < 0) {
        result = largeNumMinus(num1, largeNumReverse(num2));
    } else {
        // num1>0, num2>0
        result = seqList_Init(MAX_NUM_LENGTH);
        int carry = 0; // 进位
        int number = 0; // 两个长整数的某一位的相加结果
        int index = 0;  // 长度较短的长整数的对应位
        seqList *longNum = (num1->length > num2->length) ? num1 : num2;
        seqList *shortNum = (num1->length > num2->length) ? num2 : num1;
        for (int i = longNum->length - 1; i >= 0; --i) {
            index = shortNum->length - longNum->length + i;
            number = (index < 0) ? 0 : seqList_Get(shortNum, index);
            number = number + seqList_Get(longNum, i) + carry;
            carry = number / 10;
            number %= 10;
            seqList_Prepend(result, number);
        }
        if (carry > 0) {
            seqList_Prepend(result, carry);
        }
    }
    return result;
}

seqList *largeNumMinus(seqList *num1, seqList *num2) {
    // 已经确保传入的值中num1, num2 均为正数
    seqList *result = seqList_Init(MAX_NUM_LENGTH);
    int carry = 0; // 进位
    int number = 0; // 两个长整数的某一位的相加结果
    int index = 0;  // 长度较短的长整数的对应位
    int isReverse = (num1->length > num2->length) ? 0 : 1;
    seqList *longNum = !isReverse ? num1 : num2;
    seqList *shortNum = !isReverse ? num2 : num1;
    for (int i = longNum->length - 1; i >= 0; --i) {
        index = shortNum->length - longNum->length + i;
        number = (index < 0) ? 0 : seqList_Get(shortNum, index);
        number = seqList_Get(longNum, i) - number + carry;
        if (number < 0) {
            number += 10;
            carry = -1;
        } else {
            carry = 0;
        }
        seqList_Prepend(result, number);
    }
    // 如果结果为负，用 100..00 减去所得结果
    if (carry < 0) {
        seqList *numLarge = seqList_Init(MAX_NUM_LENGTH);
        seqList_Append(numLarge, 1);
        for (int i = 0; i < result->length; ++i) {
            seqList_Append(numLarge, 0);
        }
        result = largeNumMinus(numLarge, result);
        result = largeNumReverse(result);
    }
    // 去除结果前面的零
    while (result->length > 1) {
        if (seqList_Get(result, 0) == 0) {
            seqList_DeleteNode(result, 0);
        } else {
            break;
        }
    }
    if (isReverse) {
        result = largeNumReverse(result);
    }
    return result;
}

seqList *largeNumMultiply(seqList *num1, seqList *num2) {
    seqList *result = seqList_Init(MAX_NUM_LENGTH);
    seqList_Append(result, 0);
    int isNegative = seqList_Get(num1, 0) * seqList_Get(num2, 0);
    seqList *num3 = (seqList_Get(num1, 0) < 0) ? largeNumReverse(num1) : num1;
    seqList *num4 = (seqList_Get(num2, 0) < 0) ? largeNumReverse(num2) : num2;
    int index;
    seqList *mulNum;
    for (int i = 0; i < num3->length; ++i) {
        index = num3->length - i - 1;
        mulNum = largeNumSingleMul(num4, seqList_Get(num3, index));
        for (int j = 0; j < i; ++j) {
            seqList_Append(mulNum, 0);
        }
        result = largeNumPlus(result, mulNum);
    }
    if (isNegative < 0) {
        result = largeNumReverse(result);
    }
    return result;
}

seqList *largeNumSingleMul(seqList *num, int x) {
    seqList *result = seqList_Init(MAX_NUM_LENGTH);
    int carry = 0;
    int number;
    for (int i = num->length - 1; i >= 0; --i) {
        number = seqList_Get(num, i) * x + carry;
        carry = number / 10;
        number %= 10;
        seqList_Prepend(result, number);
    }
    if (carry > 0) {
        seqList_Prepend(result, carry);
    }
    return result;
}

seqList *largeNumReverse(seqList *num) {
    seqList *result = seqList_Init(MAX_NUM_LENGTH);
    if (seqList_Get(num, 0) < 0) {
        for (int i = 1; i < num->length; ++i) {
            seqList_Append(result, seqList_Get(num, i));
        }
    } else {
        seqList_Append(result, -1);
        for (int i = 0; i < num->length; ++i) {
            seqList_Append(result, seqList_Get(num, i));
        }
    }
    return result;
}

void largeNumPrint(seqList *num) {
    int cnt = 0;
    if (seqList_Get(num, 0) < 0 && seqList_Get(num, 1) == 0) {
        printf("0");
    } else {
        if (seqList_Get(num, 0) < 0) {
            printf("-");
            cnt = 1;
        }
        for (; cnt < num->length; ++cnt) {
            printf("%d", seqList_Get(num, cnt));
        }
    }
    printf("\n");
}
