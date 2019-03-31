#ifndef SZSTACK_H_INCLUDED
#define SZSTACK_H_INCLUDED
#define SIZE 100
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
    ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
bool isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTop(LinkStack *s);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ


#endif // SZSTACK_H_INCLUDED
