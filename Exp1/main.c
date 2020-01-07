/**
 * 模式1: 可以指定图形的宽度，并使用随机数初始化
 * 模式2: 可以读取文件，进行初始化图形指定
 */
#include <stdio.h>
#include <stdlib.h>
#include "libs/randomModule.h"
#include "libs/fileModule.h"

int main() {
    system("chcp 65001 > nul");
    int module = 0;
    do {
        printf("输入1或者2选择模式，\n1: 可以指定图形的宽度，并使用随机数初始化\n2: 可以读取文件，进行初始化图形指定\n");
        scanf("%d", &module);
    } while (module != 1 && module != 2);
    printf("-------------------------------------------\n");
    if (module == 1) {
        // 使用随机数获取初代数据，并进行迭代模拟
        randomMain();
    } else if (module == 2) {
        // 从文件读取初代数据，并进行迭代模拟
        fileMain();
    } else {
        printf("读取模式选项失败。");
    }
    system("pause");
    return 0;
}
