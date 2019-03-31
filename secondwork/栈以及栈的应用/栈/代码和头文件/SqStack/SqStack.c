#include "../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>



//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
    free(s->elem);                                          /*如果清空栈后又初始化，则必须释放先前开创的空间*/
    s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));
    if(s->elem == NULL)
        return 0;
    s->top = -1;
    s->size = sizes;
    return SUCCESS;
}

bool isEmptyStack(SqStack *s)   //判断栈是否为空
{
    return (s->top == -1 ? 1 : 0);
}

Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
    if(s->top == -1)
        return 0;
    else
        *e = *(s->elem+s->top);
        return 1;
}

Status clearStack(SqStack *s)   //清空栈
{
    if(s->top == -1)
        return 0;
    s->top = -1;
    return 1;
}

Status destroyStack(SqStack *s)  //销毁栈
{
    free(s->elem);
    free(s);
    return 1;
}

Status stackLength(SqStack *s,int *length)   //检测栈长度
{
    *length = s->top+1;
    return 1;
}

Status pushStack(SqStack *s,ElemType data)  //入栈
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

Status popStack(SqStack *s,ElemType *data)   //出栈
{
    if(s->top == -1)
    {
        printf("Sorry,the Stack is empty.\n");
        return 0;
    }
    *data = *(s->elem+(s->top--));
    return 1;
}


