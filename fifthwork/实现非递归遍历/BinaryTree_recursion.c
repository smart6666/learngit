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
        if((*T)->lchild) /* ������ */
            DestroyBiTree(&(*T)->lchild); /* ������������ */
        if((*T)->rchild) /* ���Һ��� */
            DestroyBiTree(&(*T)->rchild); /* �����Һ������� */
        free(*T); /* �ͷŸ���� */
        *T=NULL; /* ��ָ�븳0 */
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
        (*T)->data=ch;          /* ���ɸ���� */
        CreateBiTree(&(*T)->lchild, definition); /* ���������� */
        CreateBiTree(&(*T)->rchild, definition); /* ���������� */
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
        //ȡջ��Ԫ��
        getTopLStack(&s, &front);

        //����,��ջ
        visit(front->data);
        popLStack(&s);

        //������������ڣ���ջ
        if (front->rchild)
            pushLStack(&s, &front->rchild);

        //������������ڣ���ջ
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
