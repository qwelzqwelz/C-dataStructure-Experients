//
// Created by qwelzqwelz on 2020/1/3.
//

#ifndef EXP2_DOUBLECIRCLECHAINLIST_H
#define EXP2_DOUBLECIRCLECHAINLIST_H

// 双循环链表-结点
typedef struct dccNode {
    struct dccNode *prior;
    int numData;
    struct dccNode *next;
} dccNode;

// 双循环链表
typedef struct {
    int length;
    dccNode *head;
} dccList;

// 双循环链表-初始化
dccList *dccList_Init();

// 双循环链表-插入结点
int dccList_InsertNode(dccList *l, int index, dccNode *n);

// 双循环链表-插入数据(自动生成结点)
dccNode *dccList_InsertNum(dccList *l, int index, int num);

// 双循环链表-删除结点
int dccList_DeleteNode(dccList *l, int index);

// 双循环链表-删除结点并返回
dccNode *dccList_PopNode(dccList *l, int index);

// 双循环链表-获取结点
dccNode *dccList_GetNode(dccList *l, int index);

// 双循环链表-获取结点的index
int dccList_GetIndex(dccList *l, int data);

// 双循环链表-在链表的尾部添加结点
int dccList_Append(dccList *l, dccNode *n);

#endif //EXP2_DOUBLECIRCLECHAINLIST_H
