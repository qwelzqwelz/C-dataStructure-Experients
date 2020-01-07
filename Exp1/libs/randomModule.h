//
// Created by qwelzqwelz on 2019/12/22.
//

#ifndef EXP1_RANDOMMODULE_H
#define EXP1_RANDOMMODULE_H
/**
 * 模式1: 可以指定图形的宽度，并使用随机数初始化
 */
#include "minMax.h"

// 随机模式-主函数
void randomMain();

// 根据随机数，获取生命是否活着
int getRandExist();

// 随机生成生物分布图，进行初始化
void randomInit(int S[MAX_WIDTH][MAX_WIDTH], int width, int height);

// 将二维数组打印为模拟图
void printS(int S[MAX_WIDTH][MAX_WIDTH], int width, int height);

// 跟据上一代S1，模拟出S2，最终将S2赋值给S1
void nextS(int S1[MAX_WIDTH][MAX_WIDTH], int S2[MAX_WIDTH][MAX_WIDTH], int width, int height);

// 循环演化下一代
void showLoop(int S1[MAX_WIDTH][MAX_WIDTH], int S2[MAX_WIDTH][MAX_WIDTH], int width, int height);

#endif //EXP1_RANDOMMODULE_H
