//
// Created by qwelzqwelz on 2019/12/25.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

Graph *graphInit() {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->edgeList = (Edge **) malloc(sizeof(Edge *) * MAX_EDGE_LENGTH);
    g->vertexSet = setInit(MAX_VERTEX_LENGTH);
    g->edgeNum = 0;
    return g;
}

int graphAddEdge(Graph *g, char *name1, char *name2) {
    int result = 1;
    // 名字不存在则添加结点
    if (!setHas(g->vertexSet, graphGetVertex(g, name1))) {
        if (!graphAddVertex(g, name1)) {
            result = 0;
        }
    }
    if (!setHas(g->vertexSet, graphGetVertex(g, name2))) {
        if (!graphAddVertex(g, name2)) {
            result = 0;
        }
    }
    setPrint(g->vertexSet);
    // 添加图的边
    if (result && g->edgeNum >= MAX_EDGE_LENGTH) {
        result = 0;
        printf("--图的边数已经达到最大值--\n");
    } else if (result) {
        Edge *e = (Edge *) malloc(sizeof(Edge));
        e->n1 = graphGetVertex(g, name1);
        e->n2 = graphGetVertex(g, name2);
        e->weight = 1;
        g->edgeList[g->edgeNum] = e;
        g->edgeNum++;
    }
    return result;
}

Node *graphGetVertex(Graph *g, char *name) {
    return setGetNodeByData(g->vertexSet, name);
}

int graphAddVertex(Graph *g, char *name) {
    return setAdd(g->vertexSet, createNode(name));
}

Set *graphGetVertexSetCopy(Graph *g) {
    return setCopy(g->vertexSet);
}

char **graphGetShortestPath(Graph *g, char *name1, char *name2) {
    if(!graphGetVertex(g, name1) || !graphGetVertex(g, name2)){
        printf("-- 有结点不存在 --\n");
        return NULL;
    }
    Set *S = setInit(g->vertexSet->maxSize);
    setAdd(S, graphGetVertex(g, name1));
    Set *V = graphGetVertexSetCopy(g);
    if (!setDelete(V, graphGetVertex(g, name1))) {
        return NULL;
    }
    setPrint(S);
    setPrint(V);
    char **result = NULL;
    Path **dist = (Path **) malloc(sizeof(Path *) * MAX_VERTEX_LENGTH);
    int distLength = V->size;
    for (int i = 0; i < distLength; ++i) {
        dist[i] = (Path *) malloc(sizeof(Path));
        dist[i]->pathNames = (char **) malloc(sizeof(char) * MAX_VERTEX_LENGTH);
        dist[i]->dest = V->nList[i];
        dist[i]->sumWeight = graphGetEdgeWeight(g, graphGetVertex(g, name1), V->nList[i]);
        dist[i]->pathNames[0] = name1;
        dist[i]->pathNames[1] = V->nList[i]->name;
    }
    Path *minPath;
    while (!setIsEmpty(V)) {
        minPath = pathGetMin(dist, V, distLength);
        if (minPath->dest == graphGetVertex(g, name2)) {
            result = minPath->pathNames;
            if (minPath->sumWeight < MAX_VERTEX_LENGTH) {
                result[minPath->sumWeight + 1] = NULL;
            } else {
                result = NULL;
            }
            break;
        }
        setAdd(S, minPath->dest);
        setDelete(V, minPath->dest);
        pathUpdateAll(g, dist, distLength, V, minPath);
    }
    return result;
}


int graphGetEdgeWeight(Graph *g, Node *n1, Node *n2) {
    int result = 0;
    Node *v1;
    Node *v2;
    if (n1 != n2) {
        for (int i = 0; i < g->edgeNum; ++i) {
            v1 = g->edgeList[i]->n1;
            v2 = g->edgeList[i]->n2;
            if ((n1 == v1 && n2 == v2) || (n1 == v2 && n2 == v1)) {
                result = g->edgeList[i]->weight;
                break;
            }
        }
        if (!result) {
            result = MAX_VERTEX_LENGTH + 1;
        }
    }
    return result;
}

Path *pathGetMin(Path **dist, Set *V, int distLength) {
    Path *result = NULL;
    Path *testPath;
    for (int i = 0; i < V->size; ++i) {
        testPath = pathGetNode(dist, V->nList[i], distLength);
        if (!result) {
            result = testPath;
        } else {
            if (testPath->sumWeight < result->sumWeight) {
                result = testPath;
            }
        }
    }
    return result;
}

Path *pathGetNode(Path **dist, Node *node, int distLength) {
    Path *result = NULL;
    for (int j = 0; j < distLength; ++j) {
        if (dist[j]->dest == node) {
            result = dist[j];
            break;
        }
    }
    return result;
}

void pathUpdateAll(Graph *g, Path **dist, int distLength, Set *V, Path *minPath) {
    Path *path = NULL;
    int newSumWeight = 0;
    for (int i = 0; i < V->size; ++i) {
        path = pathGetNode(dist, V->nList[i], distLength);
        newSumWeight = minPath->sumWeight + graphGetEdgeWeight(g, minPath->dest, V->nList[i]);
        if (newSumWeight < MAX_VERTEX_LENGTH && newSumWeight < path->sumWeight) {
            // 更新总权值
            path->sumWeight = newSumWeight;
            // 更新路径
            for (int j = 0; j <= minPath->sumWeight; ++j) {
                path->pathNames[j] = minPath->pathNames[j];
            }
            path->pathNames[minPath->sumWeight + 1] = path->dest->name;
        }
    }
}

Node *createNode(char *name) {
    Node *n = (Node *) malloc(sizeof(Node));
    char *newName = (char *) calloc(MAX_NAME_LENGTH, sizeof(char));
    strcpy(newName, name);
    n->name = newName;
    return n;
}
