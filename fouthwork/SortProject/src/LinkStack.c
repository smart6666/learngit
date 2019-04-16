#include "../inc/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
      s->top = NULL;
      s->count = 0;
    return SUCCESS;
}

bool isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
    return (s->count == 0);
}

ElemType getTopLStack(LinkStack *s)  //得到栈顶元素
{
        return s->top->data;
}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
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

Status popLStack(LinkStack *s)   //出栈
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
