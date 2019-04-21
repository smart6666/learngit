#include"BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int isOpNum(char ch);
char nextToken(char *definition);
static int pos=0;

Status InitBiTree(BiTree *T)
{
    *T=NULL;
    return SUCCESS;
}


Status DestroyBiTree(BiTree *T)
{
    pos = 0;
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
    ch=nextToken(definition);

    (*T)=(BiTree)malloc(sizeof(BiTNode));
    if(isdigit(ch))
       (*T)->data=ch-48;
    else
        (*T)->data=ch;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
    if(!isOpNum(ch))//是操作符。前缀表达式的最后一个字符一定是操作数，所以下面的递归会停止。
    {
        CreateBiTree(&(*T)->lchild, definition); /* 构造左子树 */
        CreateBiTree(&(*T)->rchild, definition); /* 构造右子树 */
    }
    return SUCCESS;
}


char nextToken(char *definition)//括号、操作数、操作符等 都为一个字符
{

    while(definition[pos]!='\0' && definition[pos]==' ')
        {pos++;}//跳过空格
    return definition[pos++];
}

int isOpNum(char ch)//是否是操作数
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch==' ')
    {
         return 0;
    }
    return 1;
}

int Value(BiTree T)
{
    if(!isOpNum(T->data))
    {
        switch(T->data)
        {
            case '+':
                return Value(T->lchild)+Value(T->rchild);
                break;
            case '-':
                return Value(T->lchild)-Value(T->rchild);
                break;
            case '/':
                return Value(T->lchild)/Value(T->rchild);
                break;
            case '*':
                return Value(T->lchild)*Value(T->rchild);
                break;
        }
    }
    return T->data;
}
