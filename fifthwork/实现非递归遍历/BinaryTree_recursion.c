#include"BinaryTree.h"
#include "LinkStack.h"
#include "LinkStack.c"
#include<stdio.h>
#include<stdlib.h>

static int index = 0;


Status InitBiTree(BiTree *T)
{
    *T=NULL;
    return SUCCESS;
}


Status DestroyBiTree(BiTree *T)
{
    index = 0;
    if(*T)
    {
        if((*T)->lchild) /* 有左孩子 */
            DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
        if((*T)->rchild) /* 有右孩子 */
            DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
        free(*T); /* 释放根结点 */
        *T=NULL; /* 空指针赋0 */
        return SUCCESS;
    }
    return ERROR;
}

Status CreateBiTree(BiTree *T, char* definition)
{
    TElemType ch;

    ch=definition[index++];

    if(ch=='#')
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(1);
        (*T)->data=ch;          /* 生成根结点 */
        CreateBiTree(&(*T)->lchild, definition); /* 构造左子树 */
        CreateBiTree(&(*T)->rchild, definition); /* 构造右子树 */
    }
    return SUCCESS;
}

Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    LinkStack s;
    initLStack(&s);
    BiTree front;

    if (NULL == T)
        return ERROR;

    pushLStack(&s, &T);

    while (!isEmptyLStack(&s))
    {
        //取栈顶元素
        getTopLStack(&s, &front);

        //遍历,出栈
        visit(front->data);
        popLStack(&s);

        //如果右子树存在，入栈
        if (front->rchild)
            pushLStack(&s, &front->rchild);

        //如果左子树存在，入栈
        if (front->lchild)
            pushLStack(&s, &front->lchild);
    }
    return SUCCESS;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    LinkStack s;
    initLStack(&s);
    if (NULL == T)
        return ERROR;
    BiTree front = T;

    while(front || !isEmptyLStack(&s))
    {
        while(front)
        {
            pushLStack(&s, &front);
            front = front->lchild;
        }
        if(!isEmptyLStack(&s))
        {
            getTopLStack(&s, &front);
            visit(front->data);
            popLStack(&s);
            front = front->rchild;
        }
    }
    return SUCCESS;
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    LinkStack s;
    initLStack(&s);
     if (NULL == T)
        return ERROR;
    BiTree front = T, prew = NULL;
    pushLStack(&s, &front);
    while(!isEmptyLStack(&s))
    {
        getTopLStack(&s, &front);
        if((!front->lchild && !front->rchild) ||
           ((prew==front->lchild || prew==front->rchild) && prew!=NULL))
           {
               visit(front->data);
               popLStack(&s);
               prew = front;
           }
        else
        {
            if(front->rchild != NULL)
                pushLStack(&s, &front->rchild);
            if(front->lchild != NULL)
                pushLStack(&s, &front->lchild);
        }
    }
    return SUCCESS;
}
