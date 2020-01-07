//
// Created by qwelzqwelz on 2019/12/25.
//

#ifndef EXP6_GRAPH_H
#define EXP6_GRAPH_H
// 图-最大边数
#define MAX_EDGE_LENGTH 10000
// 图-最大结点数
#define MAX_VERTEX_LENGTH 100
// 图-结点中名字的最大长度
#define MAX_NAME_LENGTH 100

#include "set.h"

// 图-边
typedef struct {
    Node *n1;
    Node *n2;
    int weight;
} Edge;
// 图
typedef struct {
    Edge **edgeList;
    Set *vertexSet;
    int edgeNum;
} Graph;
// 图-路径
typedef struct {
    Node *dest;
    int sumWeight;
    char **pathNames;
} Path;

// 图初始化
Graph *graphInit();

// 图-增加一条边
int graphAddEdge(Graph *g, char *name1, char *name2);

// 图-增加一个结点
int graphAddVertex(Graph *g, char *name);

// 图-获取结点
Node *graphGetVertex(Graph *g, char *name);

// 图-获取边的权
int graphGetEdgeWeight(Graph *g, Node *n1, Node *n2);

// 图-根据目的结点获取其目前的最短路径
Path *getPathByDestNode(Path **dist, Node *node, int distLength);

// 图-从所有未确定的最小的路径中确定一条获取最小路径
Path *pathGetMin(Path **dist, Set *V, int distLength);

// 图-(在求出一条最小路径之后)更新所有未确定最小的路径
void pathUpdateAll(Graph *g, Path **dist, int distLength, Set *V, Path *minPath);

// 图-根据数据创建一个结点
Node *createNode(char *name);

// 图-获取两个人之间的最短联系路径
Path *graphGetShortestPath(Graph *g, char *name1, char *name2);

// 图-打印最短路径
void pathPrint(Path *path);

#endif //EXP6_GRAPH_H
