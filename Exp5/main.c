#include <stdio.h>
#include <stdlib.h>
#include "libs/tree.h"

void showTreeInfo(Tree *T);

Tree *createTreeFromInput();

int main() {
    system("chcp 65001 > nul");

    Tree *T = createTreeFromInput();
    showTreeInfo(T);
    char c;

    printf("请输入要查找的键：\n");
    scanf("%c", &c);
    printf("结点地址为：%p\n", treeFindNode(T->root, c));

    getchar();
    printf("请输入要插入的键值：\n");
    scanf("%c", &c);
    treeInsertNode(T, c);
    showTreeInfo(T);

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