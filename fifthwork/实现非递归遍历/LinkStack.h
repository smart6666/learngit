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



//链栈
Status initLStack(LinkStack *s);//初始化栈
bool isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s, BiTree *T);//得到栈顶元素
Status pushLStack(LinkStack *s, BiTree *T);//入栈
Status popLStack(LinkStack *s);//出栈


#endif // STACK_H_INCLUDED
