#include "../inc/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
      s->top = NULL;
      s->count = 0;
    return SUCCESS;
}

bool isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
    return (s->count == 0);
}

ElemType getTopLStack(LinkStack *s)  //�õ�ջ��Ԫ��
{
        return s->top->data;
}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
    LinkStackPtr p;
    p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(p == NULL)
        return ERROR;
    else
    {
        p->data = data;
        p->next = s->top;
        s->top = p;
        s->count++;
        return SUCCESS;
    }
}

Status popLStack(LinkStack *s)   //��ջ
{
    LinkStackPtr p;
    if(isEmptyLStack(s))
        return ERROR;
    p = s->top;
    s->top = p->next;
    free(p);
    s->count--;
    return SUCCESS;
}
