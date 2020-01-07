#include <stdio.h>
#include <stdlib.h>
#include "libs/queue.h"
#include "libs/stack.h"

#define MAX_CARD_NUM 120

queue *readCards(char *name);

void makeCard(queue *Q, stack *S1, stack *S2);

int main() {
    system("chcp 65001 > nul");
    queue *Q1 = readCards("A");
    queue *Q2 = readCards("B");
    stack *S1 = stackInit(MAX_CARD_NUM * 2); // 牌堆-栈
    stack *S2 = stackInit(MAX_CARD_NUM * 2); // 用于逆置的工具-栈
    int isATurn = 1;
    queuePrint(Q1);
    queuePrint(Q2);
    stackPrint(S1);
    stackPrint(S2);
    while (!queueIsEmpty(Q1) && !queueIsEmpty(Q2)) {
        printf("----------------------------------\n");
        if (isATurn) {
            printf("-- A出牌 --\n");
            makeCard(Q1, S1, S2);
        } else {
            printf("-- B出牌 --\n");
            makeCard(Q2, S1, S2);
        }
        isATurn = isATurn ? 0 : 1;
        printf("A手中的牌：");
        queuePrint(Q1);
        printf("B手中的牌: ");
        queuePrint(Q2);
        printf("牌堆中的牌：");
        stackPrint(S1);
        printf("----------------------------------\n");
    }
    if (queueIsEmpty(Q2)) {
        printf("-- A胜 --\n");
    } else {
        printf("-- B胜 --\n");
    }
    system("pause");
    return 0;
}

queue *readCards(char *name) {
    printf("请输入%s手中的牌(牌面为单个数字/字母)(空格隔开，回车结束):\n", name);
    char cList[MAX_CARD_NUM];
    int cardNum = 0;
    do {
        scanf("%c", &cList[cardNum]);
        if (cList[cardNum] != ' ') {
            cardNum++;
        }
//        printf("----%c----\n", cList[cardNum - 1]);
    } while (cList[cardNum - 1] != '\n');
    queue *q = queueInit(MAX_CARD_NUM);
    for (int i = 0; i < cardNum - 1; ++i) {
        if (!queueAppend(q, cList[i])) {
            printf("--入队失败--\n");
        }
    }
    return q;
}

void makeCard(queue *Q, stack *S1, stack *S2) {
    /**
     * Q: 要出牌的队列
     * S1: 牌堆-栈
     * S2: 工具栈-空栈
     */
    if (!stackIsEmpty(S1) && stackInclude(S1, queueGetHead(Q))) {
        char aCard = queuePrePop(Q);
        stackPush(S2, aCard);
        do {
            if (stackIsEmpty(S1)) {
                break;
            }
            stackPush(S2, stackPop(S1));
        } while (stackGetTop(S2) != aCard);
        while (!stackIsEmpty(S2)) {
            queueAppend(Q, stackPop(S2));
        }
    } else {
        stackPush(S1, queuePrePop(Q));
    }
}

