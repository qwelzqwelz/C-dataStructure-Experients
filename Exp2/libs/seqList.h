//
// Created by qwelzqwelz on 2020/1/2.
//

#ifndef EXP2_SEQLIST_H
#define EXP2_SEQLIST_H

// 顺序表-最大长度
#define MAX_LIST_LENGTH 2<<15
// 顺序表
typedef struct {
    int maxLength;
    int length;
    int *dataList;
} seqList;

// 顺序表-初始化
seqList *seqList_Init(int maxLength);

// 顺序表-插入结点
int seqList_InsertNode(seqList *l, int index, int data);

// 顺序表-删除结点
int seqList_DeleteNode(seqList *l, int index);

// 顺序表-设置某一结点的数据值
int seqList_Set(seqList *l, int index, int data);

// 顺序表-获取某一结点
int seqList_Get(seqList *l, int index);

// 顺序表-根据数据获取第一个符合的结点的index
int seqList_GetIndex(seqList *l, int data);

// 顺序表-在顺序表的尾部添加一个结点
int seqList_Append(seqList *l, int data);

// 顺序表-在顺序表的头部添加一个结点
int seqList_Prepend(seqList *l, int data);

// 顺序表-清空顺序表所有结点，保留顺序表
void seqList_ClearAll(seqList *l);

#endif //EXP2_SEQLIST_H
