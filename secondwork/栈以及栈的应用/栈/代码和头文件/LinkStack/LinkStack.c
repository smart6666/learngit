#include "../head/LinkStack.h"
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

Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
    if(isEmptyLStack(s))
        return ERROR;
    else
    {
        *e = s->top->data;
        return SUCCESS;
    }
}

Status clearLStack(LinkStack *s)   //清空栈
{
     if(isEmptyLStack(s))
        return ERROR;
     LinkStackPtr Node = s->top;
     while(Node)
     {
         s->top = Node->next;
         free(Node);
         Node = s->top;
     }
     return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //销毁栈
{
    if(isEmptyLStack(s))
    {
        free(s);
        return SUCCESS;
    }
    else
    {
        printf("The Stack is not empty.\n");
        printf("Please clear the Stack firstly.\n");
        return ERROR;
    }
}

Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
    *length = s->count;
    return SUCCESS;
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

Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
    LinkStackPtr p;
    if(isEmptyLStack(s))
        return ERROR;
    *data = s->top->data;
    p = s->top;
    s->top = p->next;
    free(p);
    s->count--;
    return SUCCESS;
}
