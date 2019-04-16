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



//链栈
Status initLStack(LinkStack *s);//初始化栈
bool isEmptyLStack(LinkStack *s);//判断栈是否为空
ElemType getTopLStack(LinkStack *s);//得到栈顶元素
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s);//出栈


#endif // STACK_H_INCLUDED
