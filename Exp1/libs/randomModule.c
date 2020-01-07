#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomModule.h"

void randomInit(int S[MAX_WIDTH][MAX_WIDTH], int width, int height) {
    time_t t;
    /* 初始化随机数发生器 */
    srand((unsigned) time(&t));
    for (int i = 1; i < height + 1; i++) {
        for (int j = 1; j < width + 1; j++) {
            S[i][j] = getRandExist();
        }
    }
}

void randomMain() {
    // 模式1
    int width = MIN_WIDTH;
    int height = MIN_WIDTH;
    int S1[MAX_WIDTH][MAX_WIDTH] = {0};
    int S2[MAX_WIDTH][MAX_WIDTH] = {0};
    printf("请输入宽度：");
    scanf("%d", &width);
    printf("请输入高度：");
    scanf("%d", &height);
    if (width < MIN_WIDTH - 2 || width > MAX_WIDTH - 2) {
        printf("输入宽度最小为：%d, 输入宽度最大值为：%d.", MIN_WIDTH - 2, MAX_WIDTH - 2);
    } else if (height < MIN_WIDTH - 2 || height > MAX_WIDTH - 2) {
        printf("输入高度最小为：%d, 输入高度最大值为：%d.", MIN_WIDTH - 2, MAX_WIDTH - 2);
    } else {
        randomInit(S1, width, height);
        showLoop(S1, S2, width, height);
    }
}

void showLoop(int S1[MAX_WIDTH][MAX_WIDTH], int S2[MAX_WIDTH][MAX_WIDTH], int width, int height) {
    printf("--初代--：\n");
    printS(S1, width, height);
    int Generation = 2;
    char input[100];
    while (Generation) {
        printf("输入任意非空字符回车生成下一代示意图，输入0结束：\n");
        scanf("%s", input);
        if (input[0] && input[0] == '0') {
            printf("--模拟结束--");
            break;
        }
        nextS(S1, S2, width, height);
        printf("--第%d代--：\n", Generation);
        printS(S1, width, height);
        Generation++;
    }
}

int getRandExist() {
    return (rand() > (RAND_MAX / 2)) ? 1 : 0;
}

void printS(int S[MAX_WIDTH][MAX_WIDTH], int width, int height) {
    for (int i = 0; i <= height + 1; i++) {
        for (int j = 0; j <= width + 1; j++) {
            printf((S[i][j] > 0) ? "▇" : "口");
        }
        printf("\n");
    }
}

void nextS(int S1[MAX_WIDTH][MAX_WIDTH], int S2[MAX_WIDTH][MAX_WIDTH], int width, int height) {
    int countLive = 0;
    const int Direct[][2] =
            {
                    {0,  -1},
                    {1,  -1},
                    {1,  0},
                    {1,  1},
                    {0,  1},
                    {-1, 1},
                    {-1, 0},
                    {-1, -1}
            };
    for (int i = 1; i < height + 1; i++) {
        for (int j = 1; j < width + 1; j++) {
            // 获得周围的活物数量
            countLive = 0;
            for (int k = 0; k < 8; ++k) {
                countLive += S1[i + Direct[k][0]][j + Direct[k][1]];
            }
            // 决定下一代的生死
            if (S1[i][j] > 0) {
                if (countLive == 2 || countLive == 3) {
                    S2[i][j] = 1;
                } else {
                    S2[i][j] = 0;
                }
            } else {
                if (countLive == 3) {
                    S2[i][j] = 1;
                } else {
                    S2[i][j] = 0;
                }
            }
        }
    }
    for (int i = 1; i < height + 1; i++) {
        for (int j = 1; j < width + 1; j++) {
            S1[i][j] = S2[i][j];
        }
    }
}
