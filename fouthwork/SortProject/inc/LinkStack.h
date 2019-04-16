#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include<stdbool.h>
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
ElemType getTopLStack(LinkStack *s);//�õ�ջ��Ԫ��
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s);//��ջ


#endif // STACK_H_INCLUDED
