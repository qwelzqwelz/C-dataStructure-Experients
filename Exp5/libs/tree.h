//
// Created by qwelzqwelz on 2019/12/23.
//

#ifndef EXP5_TREE_H
#define EXP5_TREE_H

typedef void (*Function)(void);

//树的结点
typedef struct node {
    char data;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

//树根
typedef struct {
    Node *root;
} Tree;

// 树的初始化
Tree *treeInit();

//树-插入结点
Node *treeInsertNode(Tree *tree, char data);

//树-删除结点
void treeDeleteNode(Node *node);

//树-查找结点
Node *treeFindNode(Node *node, char c);

// 重新设置父结点
void resetParentNode(Node *node, Node *newChild);

//树的中序遍历
void treeInOrder(Node *node);

//树的先序遍历
void treePreOrder(Node *node);

//树的后序遍历
void treePostOrder(Node *node);

// 树的层序遍历
void treeLevelOrder(Node *node, Function func(Node *), int *degreeList);

// 求树的宽度
int treeGetWidth(Node *node);

// 求树的深度
int treeGetDepth(Node *node);


void nodeGetDrgree(Node *node);

void treeGetDegree(Node *node, int *degreeList);

// 求结点的度
int nodeGetDegree(Node *node);

// 打印结点中的字符数据
void nodePrint(Node *node);

#endif //EXP5_TREE_H
