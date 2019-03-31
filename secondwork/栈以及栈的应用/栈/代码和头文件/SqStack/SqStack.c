#include "../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>



//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
    free(s->elem);                                          /*������ջ���ֳ�ʼ����������ͷ���ǰ�����Ŀռ�*/
    s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));
    if(s->elem == NULL)
        return 0;
    s->top = -1;
    s->size = sizes;
    return SUCCESS;
}

bool isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
    return (s->top == -1 ? 1 : 0);
}

Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
    if(s->top == -1)
        return 0;
    else
        *e = *(s->elem+s->top);
        return 1;
}

Status clearStack(SqStack *s)   //���ջ
{
    if(s->top == -1)
        return 0;
    s->top = -1;
    return 1;
}

Status destroyStack(SqStack *s)  //����ջ
{
    free(s->elem);
    free(s);
    return 1;
}

Status stackLength(SqStack *s,int *length)   //���ջ����
{
    *length = s->top+1;
    return 1;
}

Status pushStack(SqStack *s,ElemType data)  //��ջ
{
    if(s->top == s->size-1)
    {
        printf("The Stack is full.\n");
        return 0;
    }
    else
    {
        *(s->elem+(++s->top)) = data;
        return 1;
    }
}

Status popStack(SqStack *s,ElemType *data)   //��ջ
{
    if(s->top == -1)
    {
        printf("Sorry,the Stack is empty.\n");
        return 0;
    }
    *data = *(s->elem+(s->top--));
    return 1;
}


