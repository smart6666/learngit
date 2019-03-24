/*linkedList.c--双向链表基本操作*/
#include<stdio.h>
#include<stdlib.h>
#include "../head/duLinkedList.h"
#include"duLinkedList.c"
void shownum( ElemType e);
int main(void)
{
    DuLinkedList num,pnew,scan;
    ElemType e;
    int i,j,count=0;                                     /*设置count为计数器*/
    Status flag;

    /*初始化*/
    flag=InitList_DuL(&num);
    if(flag==ERROR)                                      /*若头结点设置失败，则退出程序*/
        exit(1);

    /*获取用户输入并存储*/
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


    while(getchar()!='\n')                                  /*清理缓冲区*/
        continue;
    if(num->next==NULL)                                     /*如果链表没有数据，则退出程序*/
    {
        printf("Bye!\n");
        return 0;
    }


    /*显示                */
    printf("Here is the num list:\n");
    TraverseList_DuL(num, shownum);


    /*删除结点             */
    printf("Please input the Node you want to delete (a positive integer and <= %d): ",count);
    while(scanf("%d",&i)!=1||(i<0||i>count))                /*只能输入链表有的位置*/
    {                                                       /*若输入不合法则重新输入*/
        while(getchar()!='\n')
        continue;
        printf("Please input a positive integer: ");
    }
    for(j=0,scan=num;j<i-1;j++)                             /*寻找要删除的结点的前一个*/
        scan=scan->next;
    DeleteList_DuL(scan, &e);                               /*调用删除函数*/
    printf("You hava delete the %d Node and the data is: %d\n",i,e);
    printf("Here is the new List:\n");
    TraverseList_DuL(num, shownum);                         /*显示操作过后的链表*/



    /*增加结点*/
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


    while(getchar()!='\n')                                  /*清理缓冲区*/
        continue;


    /*显示                */
    printf("Here is the num list:\n");
    TraverseList_DuL(num, shownum);


    /*释放链表*/
    DestroyList_DuL(&num);
    getchar();
    getchar();

    return 0;

}

void shownum( ElemType e)
{
    printf("The data: %d\n",e);
}
