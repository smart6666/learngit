#include"../head/LQueue.h"
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

Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(IsEmptyLQueue(Q))
        return 0;
    memcpy(e, Q->front->next->data,len);
    return 1;
}

int LengthLQueue(LQueue *Q)
{
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if(NULL == p)
        return 0;
    p->data = (void*)malloc(len);
    memcpy(p->data, data, len);
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

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int size))
{
    if(IsEmptyLQueue(Q))
        return 0;
    Node *p = Q->front->next;
    int i=0;
    while(p != NULL)
    {
        if(i%5 == 0) printf("\n");
        foo(p->data, len);
        p = p->next;
        i++;
    }
    printf("\n"); 
    return 1;
}

void LPrint(void *q, int size)
{
    if(size == sizeof(char))
        printf("%c",*(char*)q);
    else if(size == sizeof(double))
        printf("%lf", *(double*)q);
    else if(size == sizeof(int))
        printf("%d", *(int*)q);
    printf("  ");
}

