#include"SZstack.h"

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

Status getTop(LinkStack *s)  //�õ�ջ��Ԫ��
{
    if(s == NULL)
    {
        return ERROR;
    }
    if(s->top == NULL)
    {
        return ERROR;
    }
    return s->top->data;
}

Status clearLStack(LinkStack *s)   //���ջ
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

Status destroyLStack(LinkStack *s)   //����ջ
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

Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
    *length = s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s,int data)   //��ջ
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

Status popLStack(LinkStack *s,int *data)   //��ջ
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
