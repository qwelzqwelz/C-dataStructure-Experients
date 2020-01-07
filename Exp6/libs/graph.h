//
// Created by qwelzqwelz on 2019/12/25.
//

#ifndef EXP6_GRAPH_H
#define EXP6_GRAPH_H
#define MAX_EDGE_LENGTH 10000
#define MAX_VERTEX_LENGTH 100
#define MAX_NAME_LENGTH 100

#include "set.h"

typedef struct {
    Node *n1;
    Node *n2;
    int weight;
} Edge;

typedef struct {
    Edge **edgeList;
    Set *vertexSet;
    int edgeNum;
} Graph;

typedef struct {
    Node *dest;
    int sumWeight;
    char **pathNames;
} Path;

Graph *graphInit();

int graphAddEdge(Graph *g, char *name1, char *name2);

int graphAddVertex(Graph *g, char *name);

Node *graphGetVertex(Graph *g, char *name);

int graphGetEdgeWeight(Graph *g, Node *n1, Node *n2);

Path *pathGetNode(Path **dist, Node *node, int distLength);

Path *pathGetMin(Path **dist, Set *V, int distLength);

void pathUpdateAll(Graph *g, Path **dist, int distLength, Set *V, Path *minPath);

Node *createNode(char *name);

char **graphGetShortestPath(Graph *g, char *name1, char *name2);

#endif //EXP6_GRAPH_H
