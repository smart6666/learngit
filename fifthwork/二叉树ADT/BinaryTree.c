#include"BinaryTree.h"
#include"LQueue.h"
#include"LQueue.c"
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
    if(T == NULL)
        return ERROR;
    (visit)(T->data);
    PreOrderTraverse(T->lchild, visit);
    PreOrderTraverse(T->rchild, visit);
    return SUCCESS;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    InOrderTraverse(T->lchild, visit);
    (visit)(T->data);
    InOrderTraverse(T->rchild, visit);
    return SUCCESS;
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    PostOrderTraverse(T->lchild, visit);
    PostOrderTraverse(T->rchild, visit);
    (visit)(T->data);
    return SUCCESS;
}

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    BiTNode front;
    LQueue q;
    InitLQueue(&q);
    if(T == NULL)
        return ERROR;

    EnLQueue(&q, T);
    while(!IsEmptyLQueue(&q))
    {
         GetHeadLQueue(&q, &front);
         visit(front.data);
         DeLQueue(&q);
         if (front.lchild)
            EnLQueue(&q, front.lchild);
         if (front.rchild)
            EnLQueue(&q, front.rchild);
    }
    return SUCCESS;
}



