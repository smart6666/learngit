#include"../head/AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void InitAQueue(AQueue *Q)
{
    for(int i=0; i<MAXQUEUE; i++)
        Q->data[i]=(void*)malloc(Q->length);
    Q->front = 0;
    Q->rear = 0;
}

void DestoryAQueue(AQueue *Q)
{
    for(int i=0; i<MAXQUEUE; i++)
        free(Q->data[i]);
}

Status IsFullAQueue(const AQueue *Q)
{
    if((Q->rear+1)%MAXQUEUE == Q->front)
        return 1;
    else
        return 0;
}

Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->front == Q->rear)
        return 1;
    else
        return 0;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(Q->rear == Q->front)
        return 0;
    int i = Q->front;
    i = (i+1)%MAXQUEUE;
    memcpy(e, Q->data[i], Q->length);
    return 1;
}

int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
}

Status EnAQueue(AQueue *Q, void *data)
{
    if(IsFullAQueue(Q))
        return 0;
    Q->rear = (Q->rear+1)%MAXQUEUE;
    memcpy(Q->data[Q->rear], data, Q->length);
}

Status DeAQueue(AQueue *Q)
{
    if(Q->front == Q->rear)
        return 0;
    Q->front = (Q->front+1)%MAXQUEUE;
    return 1;
}

void ClearAQueue(AQueue *Q)
{
    if(IsEmptyAQueue(Q))
        return;
    Q->front = 0;
    Q->rear = 0;
    return;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int size))
{
    if(Q->front == Q->rear)
        return 0;
    int i = Q->front+1;
    printf("Here is the data: ");
    while(i<=(MAXQUEUE-Q->front+Q->rear)%MAXQUEUE)
    {
        foo(Q->data[i], Q->length);
        i = (i+1)%MAXQUEUE;
    }
    printf("\n");
    return 1;
}

void APrint(void *q,int size)
{
     if(size == sizeof(char))
        printf("%c",*(char*)q);
    else if(size == sizeof(double))
        printf("%lf", *(double*)q);
    else if(size == sizeof(int))
        printf("%d", *(int*)q);
    printf("  ");
}
