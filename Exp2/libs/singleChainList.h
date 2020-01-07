//
// Created by qwelzqwelz on 2020/1/2.
//

#ifndef EXP2_SINGLECHAINLIST_H
#define EXP2_SINGLECHAINLIST_H

// 单链表-结点
typedef struct scNode {
    int numData;
    struct scNode *next;
} scNode;
// 单链表
typedef struct {
    scNode *head;
    scNode *tail;
    int length;
} scList;

// 单链表-初始化
scList *scList_Init();

// 单链表-插入结点
int scList_InsertNode(scList *l, int index, scNode *n);

// 单链表-插入数字(自动生成结点)
scNode *scList_InsertNum(scList *l, int index, int num);

// 单链表-删除结点
int scList_DeleteNode(scList *l, int index);

// 单链表-删除并返回结点
scNode *scList_PopNode(scList *l, int index);

// 单链表-读取指定index的结点
scNode *scList_GetNode(scList *l, int index);

// 单链表-根据结点获取index
int scList_GetIndex(scList *l, int data);

// 单链表-在链表的最后插入结点
int scList_Append(scList *l, scNode *n);

#endif //EXP2_SINGLECHAINLIST_H
