//
// Created by qwelzqwelz on 2019/12/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "queue.h"

/**
 * 左结点 < 父结点 < 右结点
 */
// 树的初始化
Tree *treeInit() {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}

//树-插入结点
Node *treeInsertNode(Tree *tree, char data) {
    Node *node = (Node *) malloc(sizeof(Node));//创建一个节点
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    if (tree->root == NULL)         // 判断树是不是空树
    {
        tree->root = node;
    } else {                //不是空树
        Node *temp = tree->root;    // 从树根开始
        while (temp != NULL) {
            if (data < temp->data)  // 小于就进左儿子
            {
                if (temp->left == NULL) {
                    temp->left = node;
                    node->parent = temp;
                    break;
                } else {    // 继续判断
                    temp = temp->left;
                }
            } else {        // 否则进右儿子
                if (temp->right == NULL) {
                    temp->right = node;
                    node->parent = temp;
                    break;
                } else {    // 继续判断
                    temp = temp->right;
                }
            }
        }
    }
    return node;
}

//树-删除结点(非根结点)
void treeDeleteNode(Node *node) {
    if (!node) {
        printf("--空结点，无法删除--\n");
    } else if (!node->left && !node->right) {
        resetParentNode(node, NULL);
    } else if (!node->left) {
        node->right->parent = node->parent;
        resetParentNode(node, node->right);
    } else if (!node->right) {
        node->left->parent = node->parent;
        resetParentNode(node, node->left);
    } else {
        // 找到右分支的最左侧子孙结点
        Node *newNode = node->right;
        while (newNode && newNode->left) {
            newNode = newNode->left;
        }
        if (newNode->parent->left == newNode) {
            newNode->parent->left = NULL;
        }
        // 将右分支的最左侧结点替换为新结点
        resetParentNode(node, newNode);
        node->left->parent = newNode;
        newNode->parent = node->parent;
        newNode->left = node->left;
    }
}

void resetParentNode(Node *node, Node *newChild) {
    if (node->parent) {
        if (node->parent->left == node) {
            node->parent->left = newChild;
        } else if (node->parent->right == node) {
            node->parent->right = newChild;
        }
    }
}

//树-查找结点
Node *treeFindNode(Node *node, char c) {
    Node *result = NULL;
    while (node && !result) {
        if (node->data == c) {
            result = node;
            break;
        }
        if (node->data > c) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (result) {
        printf("the result is : %c\n", result->data);
    }
    return result;
}


//树的中序遍历
void treeInOrder(Node *node) {
    if (node != NULL) {
        treeInOrder(node->left);
        printf("%c ", node->data);
        treeInOrder(node->right);
    }
}

//树的先序遍历
void treePreOrder(Node *node) {
    if (node != NULL) {
        printf("%c ", node->data);
        treePreOrder(node->left);
        treePreOrder(node->right);
    }
}

//树的后序遍历
void treePostOrder(Node *node) {
    if (node != NULL) {
        treePostOrder(node->left);
        treePostOrder(node->right);
        printf("%c ", node->data);
    }
}

// 树的层序遍历
void treeLevelOrder(Node *node, Function func(Node *), int *degreeList) {
    if (node == NULL) {
        return;
    }
    queue *Q = queueInit(MAX_QUEUE_LENGTH);
    queueAppend(Q, node);
    while (!queueIsEmpty(Q)) {
        node = queuePrePop(Q);
        func(node);
        degreeList[(int) nodeGetDegree(node)]++;
        if (node->left) {
            queueAppend(Q, node->left);
        }
        if (node->right) {
            queueAppend(Q, node->right);
        }
    }
}

// 求树的宽度
int treeGetWidth(Node *node) {
    int result = 0;
    if (node == NULL) {
        return result;
    }
    queue *Q = queueInit(MAX_QUEUE_LENGTH);
    int width = 1;
    int nextWidth = 0;
    queueAppend(Q, node);
    while (!queueIsEmpty(Q)) {
        nextWidth = 0;
        for (int i = 0; i < width; ++i) {
            node = queuePrePop(Q);
            if (node->left) {
                queueAppend(Q, node->left);
                nextWidth++;
            }
            if (node->right) {
                queueAppend(Q, node->right);
                nextWidth++;
            }
        }
        width = nextWidth;
        if (result < width) {
            result = width;
        }
    }
    return result;
}

// 求树的深度
int treeGetDepth(Node *node) {
    int result = 0;
    if (node) {
        int m = treeGetDepth(node->left);
        int n = treeGetDepth(node->right);
        result = ((m > n) ? m : n) + 1;
    }
    return result;
}

// 统计度为0，1，2的结点个数
int nodeGetDegree(Node *node) {
    int result = 1;
    if (node) {
        if (node->left && node->right) {
            result = 2;
        } else if (!node->left && !node->right) {
            result = 0;
        }
    }
    return result;
}

void nodePrint(Node *node) {
    printf("%c ", node->data);
}