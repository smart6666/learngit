/*linkedList.c--���������������*/
#include<stdio.h>
#include<stdlib.h>
#include"../head/linkedList.h"
#include"linkedList.c"
void shownum( ElemType e);
int main(void)
{
    LinkedList num,pnew,scan;
    ElemType e;
    int i,j,count=0;                                /*����countΪ������*/
    Status flag;

    /*��ʼ��*/
    flag=InitList(&num);                            /*��ͷ�������ʧ�ܣ����˳�����*/
    if(flag==ERROR)
        exit(1);

    /*��ȡ�û����벢�洢*/
    scan=num;
    puts("Please input the first number: ");
    while(scanf("%d",&e)==1)
    {
        pnew=(LNode*)malloc(sizeof(LNode));
        if(pnew==NULL)
        {
            printf("ERROR\n");
            exit(1);
        }
        pnew->data=e;
        if(InsertList(scan, pnew)==ERROR)
        {
            printf("ERROR\n");
            exit(1);
        }
        scan=scan->next;
        count++;
        puts("Please enter next number (q to quit): ");
    }


    while(getchar()!='\n')                          /*��������*/
        continue;
    if(num->next==NULL)                             /*�������û�����ݣ����˳�����*/
    {
        printf("Bye!\n");
        return 0;
    }


    /*��ʾ                */
    printf("Here is the num list:\n");
    TraverseList(num, shownum);


    /*ɾ�����             */
    printf("Please input the Node you want to delete (a positive integer and <= %d): ",count);
    while(scanf("%d",&i)!=1||(i<0||i>count))          /*ֻ�����������е�λ��*/
    {                                                 /*�����벻�Ϸ�����������*/
        while(getchar()!='\n')
        continue;
        printf("Please input a correct integer: ");
    }
    for(j=0,scan=num;j<i-1;j++)                       /*Ѱ��Ҫɾ���Ľ���ǰһ��*/
        scan=scan->next;
    DeleteList(scan, &e);                             /*����ɾ������*/
    printf("You hava delete the %d Node and the data is: %d\n",i,e);
    printf("Here is the new List:\n");
    TraverseList(num, shownum);                        /*��ʾ�������������*/


    /*��������,�������ַ*/
    printf("Please input the data you want to find: ");
    while(scanf("%d",&e)!=1)                           /*�����벻�Ϸ�����������*/
    {
        while(getchar()!='\n')
        continue;
        printf("Please input a correct integer: ");
    }
    SearchList(num,e);                                  /*���ò�ѯ����*/


    /*���ת�ú������*/
    ReverseList(&num);
    printf("\nHere is the Reverse num list:\n");
    TraverseList(num, shownum);



    /*ת��ż�����*/
     ReverseEvenList(&num);
     printf("Here is the ReverseEvenlist:\n");
     TraverseList(num, shownum);


    /*�����м���*/
    LinkedList pt;
    pt=FindMidNode(&num);
    if(pt!=num)
        printf("\nThe mid node's num is %d\n\n",pt->data);
    else
        printf("\nNo mid node.\n");



    /*�ж��Ƿ�ɻ�*/
    if(IsLoopList(num)==ERROR)
        printf("The num list is not loop list\n");
    else
        printf("The num list is a loop list\n");



    /*�ͷ�����*/
    DestroyList(&num);
    getchar();
    getchar();

    return 0;
}

void shownum( ElemType e)
{
    printf("The data: %d\n",e);
}
