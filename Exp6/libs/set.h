//
// Created by qwelzqwelz on 2019/12/25.
//

#ifndef EXP6_SET_H
#define EXP6_SET_H
// 集合-结点
typedef struct {
    char *name;
} Node;

// 集合
typedef struct {
    Node **nList;
    int size;
    int maxSize;
} Set;

// 集合-初始化
Set *setInit(int setSize);

// 集合-检测某元素是否在集合中
int setHas(Set *s, Node *n);

// 集合-添加元素
int setAdd(Set *s, Node *n);

// 集合-删除元素
int setDelete(Set *s, Node *n);

// 集合-深拷贝
Set *setCopy(Set *s);

// 集合-判断集合是否为空
int setIsEmpty(Set *s);

// 集合-根据数据获取集合的某一元素
Node *setGetNodeByData(Set *s, char *name);

// 集合-打印全部元素
void setPrint(Set *s);

#endif //EXP6_SET_H
