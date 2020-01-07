//
// Created by qwelzqwelz on 2019/12/25.
//

#ifndef EXP6_SET_H
#define EXP6_SET_H
typedef struct {
    char *name;
} Node;

typedef struct {
    Node **nList;
    int size;
    int maxSize;
} Set;

Set *setInit(int setSize);

int setHas(Set *s, Node *n);

int setAdd(Set *s, Node *n);

int setDelete(Set *s, Node *n);

Set *setCopy(Set *s);

int setIsEmpty(Set *s);

Node *setGetNodeByData(Set *s, char *name);

void setPrint(Set *s);

#endif //EXP6_SET_H
