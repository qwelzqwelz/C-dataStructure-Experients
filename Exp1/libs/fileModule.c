//
// Created by qwelzqwelz on 2019/12/22.
//
#include <stdio.h>
#include "fileModule.h"
#include "randomModule.h"

void fileMain() {
    char filePath[500];
    int S3[MAX_WIDTH][MAX_WIDTH] = {0};
    int S4[MAX_WIDTH][MAX_WIDTH] = {0};

    printf("请输入文件路径，文件每行字符最多%d 个：\n", MAX_WIDTH - 2);
    scanf("%s", &filePath);
    FILE *f = fopen(filePath, "r");
    int wH[2];
    fileInit(f, S3, wH);
    int width = wH[0];
    int height = wH[1];
    fclose(f);
    if (!width) {
        printf("-- 文件读取失败 --\n");
    } else {
        showLoop(S3, S4, width, height);
    }
}

void fileInit(FILE *f, int S[MAX_WIDTH][MAX_WIDTH], int wH[]) {
    int width = 0;
    int lineWidth = 0;
    int height = 0;
    char buf[MAX_WIDTH - 1];
    do {
        if (fgets(buf, MAX_WIDTH, f) == NULL) {
            break;
        }
        width = 0;
        height++;
        for (int i = 0; i < MAX_WIDTH - 2 + 1; ++i) {
            if (buf[i] == '\0' || buf[i] == '\n') {
                if (height > MAX_WIDTH - 2) {
                    printf("行数超过最大限制：%d\n", MAX_WIDTH - 2);
                    lineWidth = 0;
                    break;
                } else {
                    if (height == 1) {
                        lineWidth = width;
                    } else if (width != lineWidth) {
                        printf("行宽不匹配，上一行行宽%d，此行行宽%d.\n", lineWidth, width);
                        lineWidth = 0;
                        break;
                    }
                }
                break;
            } else if (buf[i] != ' ' && buf[i] != 'x') {
                printf("文件字符必须是空格或者x, 出现其他字符'%c'，在第%d行。\n", buf[i], height);
                lineWidth = 0;
                break;
            } else {
                if (width > MAX_WIDTH - 2) {
                    printf("第%d行的行宽超过最大限制：%d", height, MAX_WIDTH - 2);
                    lineWidth = 0;
                    break;
                } else if (buf[i]) {
                    width++;
                    if (buf[i] == 'x') {
                        S[height][width] = 1;
                    }
                } else {
                    width++;
                    S[height][width] = 0;
                }
            }
        }
    } while (lineWidth);
    wH[0] = lineWidth;
    wH[1] = height;
}

