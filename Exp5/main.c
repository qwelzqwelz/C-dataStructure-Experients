#include <stdio.h>
#include <stdlib.h>
#include "libs/tree.h"

// 显示构造的树的信息
void showTreeInfo(Tree *T);

// 根据标准输入创建一棵树
Tree *createTreeFromInput();

int main() {
    system("chcp 65001 > nul");
    // 初始化一棵树
    Tree *T = createTreeFromInput();
    /**
     * 显示这棵树的信息，包括：
     * 1. 按先序、中序、后序、层序遍历这棵二叉树，
     * 2. 求二叉树的深度、宽度，
     * 3. 统计度为0，1，2的结点个数
     */
    showTreeInfo(T);
    char c;

    // 根据给定的键查找树结点
    printf("请输入要查找的键：\n");
    scanf("%c", &c);
    printf("结点地址为：%p\n", treeFindNode(T->root, c));

    // 插入结点
    getchar();
    printf("请输入要插入的键值：\n");
    scanf("%c", &c);
    treeInsertNode(T, c);
    showTreeInfo(T);

    // 删除结点
    getchar();
    printf("请输入要删除的键：\n");
    scanf("%c", &c);
    treeDeleteNode(treeFindNode(T->root, c));
    showTreeInfo(T);

    system("pause");
    return 0;
}

Tree *createTreeFromInput() {
    printf("输入字符序列(忽略空格)，用来构造树（回车结束）:\n");
    char c;
    Tree *T = treeInit();
    do {
        scanf("%c", &c);
        if (c == '\n') {
            break;
        }
        if (c == ' ') {
            continue;
        } else {
            treeInsertNode(T, c);
        }
    } while (1);
    return T;
}

void showTreeInfo(Tree *T) {
    printf("--------------------------------\n");
    printf("\n--前序遍历--\n");
    treePreOrder(T->root);
    printf("\n--中序遍历--\n");
    treeInOrder(T->root);
    printf("\n--后序遍历--\n");
    treePostOrder(T->root);
    int degreeList[3] = {0};
    printf("\n--层次遍历--\n");
    treeLevelOrder(T->root, (Function (*)(Node *)) nodePrint, degreeList);
    printf("\n--度的统计--\n");
    for (
            int i = 0;
            i < 3; ++i) {
        printf("度为%d的结点数量为：%d;\n", i, degreeList[i]);
    }
    printf(">>>树的深度: %d;\n", treeGetDepth(T->root));
    printf(">>>树的宽度: %d;\n", treeGetWidth(T->root));
    printf("--------------------------------\n");
}