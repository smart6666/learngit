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
    ch=nextToken(definition);

    (*T)=(BiTree)malloc(sizeof(BiTNode));
    if(isdigit(ch))
       (*T)->data=ch-48;
    else
        (*T)->data=ch;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
    if(!isOpNum(ch))//�ǲ�������ǰ׺���ʽ�����һ���ַ�һ���ǲ���������������ĵݹ��ֹͣ��
    {
        CreateBiTree(&(*T)->lchild, definition); /* ���������� */
        CreateBiTree(&(*T)->rchild, definition); /* ���������� */
    }
    return SUCCESS;
}


char nextToken(char *definition)//���š����������������� ��Ϊһ���ַ�
{

    while(definition[pos]!='\0' && definition[pos]==' ')
        {pos++;}//�����ո�
    return definition[pos++];
}

int isOpNum(char ch)//�Ƿ��ǲ�����
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
