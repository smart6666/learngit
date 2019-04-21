#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include<stdbool.h>
#include"BinaryTree.h"


typedef  struct StackNode
{
	BiTree T;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
bool isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s, BiTree *T);//�õ�ջ��Ԫ��
Status pushLStack(LinkStack *s, BiTree *T);//��ջ
Status popLStack(LinkStack *s);//��ջ


#endif // STACK_H_INCLUDED
