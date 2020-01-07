//
// Created by qwelzqwelz on 2019/12/22.
//

#ifndef EXP1_FILEMODULE_H
#define EXP1_FILEMODULE_H
/**
 * 模式2: 可以读取文件，进行初始化图形指定
 */
#include "minMax.h"

// 读取文件模式-主函数
void fileMain();

// 根据文件获取初始化数据
void fileInit(FILE *f, int S[MAX_WIDTH][MAX_WIDTH], int wH[]);

#endif //EXP1_FILEMODULE_H
