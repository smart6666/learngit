#include"LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int len;

void InitLQueue(LQueue *Q)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if(NULL == p)
        return ;
    p->next = NULL;
    Q->front = p;
    Q->rear = p;
    return ;
}

void DestoryLQueue(LQueue *Q)
{
    if(IsEmptyLQueue(Q))
        return ;
    ClearLQueue(Q);
    free(Q->front);

}

Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->front == Q->rear)
        return 1;
    else
        return 0;
}

Status GetHeadLQueue(LQueue *Q, BiTNode *T)
{
    if(IsEmptyLQueue(Q))
        return 0;
    *T = *Q->front->next->T;
    return 1;
}


Status EnLQueue(LQueue *Q, BiTNode *T)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if(NULL == p)
        return 0;
    p->T = (BiTNode *)malloc(sizeof(BiTNode));
    *p->T = *T;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return 1;
}

Status DeLQueue(LQueue *Q)
{
    if(IsEmptyLQueue(Q))
        return 0;
    Node *p = Q->front->next;
    Q->front->next = p->next;
    if(NULL == Q->front->next)
        Q->rear = Q->front;
    free(p);
    return 1;
}

void ClearLQueue(LQueue *Q)
{
    if(IsEmptyLQueue(Q))
        return ;
    Node *p, *q;
    Q->rear = Q->front;
    p = Q->front->next;
    while(NULL != p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    free(p);
    return ;
}
