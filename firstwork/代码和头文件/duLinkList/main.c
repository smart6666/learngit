/*linkedList.c--˫�������������*/
#include<stdio.h>
#include<stdlib.h>
#include "../head/duLinkedList.h"
#include"duLinkedList.c"
void shownum( ElemType e);
int main(void)
{
    DuLinkedList num,pnew,scan;
    ElemType e;
    int i,j,count=0;                                     /*����countΪ������*/
    Status flag;

    /*��ʼ��*/
    flag=InitList_DuL(&num);
    if(flag==ERROR)                                      /*��ͷ�������ʧ�ܣ����˳�����*/
        exit(1);

    /*��ȡ�û����벢�洢*/
    scan=num;
    puts("Please input the first number: ");
    while(scanf("%d",&e)==1)
    {
        pnew=(DuLNode*)malloc(sizeof(DuLNode));
        if(pnew==NULL)
        {
            printf("ERROR\n");
            exit(1);
        }
        pnew->data=e;
        if(InsertAfterList_DuL(scan, pnew)==ERROR)
        {
            printf("ERROR\n");
            exit(1);
        }
        scan=scan->next;
        count++;
        puts("Please enter next number (q to quit): ");
    }


    while(getchar()!='\n')                                  /*��������*/
        continue;
    if(num->next==NULL)                                     /*�������û�����ݣ����˳�����*/
    {
        printf("Bye!\n");
        return 0;
    }


    /*��ʾ                */
    printf("Here is the num list:\n");
    TraverseList_DuL(num, shownum);


    /*ɾ�����             */
    printf("Please input the Node you want to delete (a positive integer and <= %d): ",count);
    while(scanf("%d",&i)!=1||(i<0||i>count))                /*ֻ�����������е�λ��*/
    {                                                       /*�����벻�Ϸ�����������*/
        while(getchar()!='\n')
        continue;
        printf("Please input a positive integer: ");
    }
    for(j=0,scan=num;j<i-1;j++)                             /*Ѱ��Ҫɾ���Ľ���ǰһ��*/
        scan=scan->next;
    DeleteList_DuL(scan, &e);                               /*����ɾ������*/
    printf("You hava delete the %d Node and the data is: %d\n",i,e);
    printf("Here is the new List:\n");
    TraverseList_DuL(num, shownum);                         /*��ʾ�������������*/



    /*���ӽ��*/
    scan=num->next;
    printf("Please input the data you want to insert the head of the list: ");
    while(scanf("%d",&e)==1)
    {
        pnew=(DuLNode*)malloc(sizeof(DuLNode));
        if(pnew==NULL)
        {
            printf("ERROR\n");
            exit(1);
        }
        pnew->data=e;
        if(InsertBeforeList_DuL(scan, pnew)==ERROR)
        {
            printf("ERROR\n");
            exit(1);
        }
        scan=scan->prior;
        count++;
        puts("Please enter next number (q to quit): ");
    }


    while(getchar()!='\n')                                  /*��������*/
        continue;


    /*��ʾ                */
    printf("Here is the num list:\n");
    TraverseList_DuL(num, shownum);


    /*�ͷ�����*/
    DestroyList_DuL(&num);
    getchar();
    getchar();

    return 0;

}

void shownum( ElemType e)
{
    printf("The data: %d\n",e);
}
