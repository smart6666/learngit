/*linkedList.c--单向链表基本操作*/
#include<stdio.h>
#include<stdlib.h>
#include"../head/linkedList.h"
#include"linkedList.c"
void shownum( ElemType e);
int main(void)
{
    LinkedList num,pnew,scan;
    ElemType e;
    int i,j,count=0;                                /*设置count为计数器*/
    Status flag;

    /*初始化*/
    flag=InitList(&num);                            /*若头结点设置失败，则退出程序*/
    if(flag==ERROR)
        exit(1);

    /*获取用户输入并存储*/
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


    while(getchar()!='\n')                          /*清理缓冲区*/
        continue;
    if(num->next==NULL)                             /*如果链表没有数据，则退出程序*/
    {
        printf("Bye!\n");
        return 0;
    }


    /*显示                */
    printf("Here is the num list:\n");
    TraverseList(num, shownum);


    /*删除结点             */
    printf("Please input the Node you want to delete (a positive integer and <= %d): ",count);
    while(scanf("%d",&i)!=1||(i<0||i>count))          /*只能输入链表有的位置*/
    {                                                 /*若输入不合法则重新输入*/
        while(getchar()!='\n')
        continue;
        printf("Please input a correct integer: ");
    }
    for(j=0,scan=num;j<i-1;j++)                       /*寻找要删除的结点的前一个*/
        scan=scan->next;
    DeleteList(scan, &e);                             /*调用删除函数*/
    printf("You hava delete the %d Node and the data is: %d\n",i,e);
    printf("Here is the new List:\n");
    TraverseList(num, shownum);                        /*显示操作过后的链表*/


    /*查找数据,并输出地址*/
    printf("Please input the data you want to find: ");
    while(scanf("%d",&e)!=1)                           /*若输入不合法则重新输入*/
    {
        while(getchar()!='\n')
        continue;
        printf("Please input a correct integer: ");
    }
    SearchList(num,e);                                  /*调用查询函数*/


    /*输出转置后的链表*/
    ReverseList(&num);
    printf("\nHere is the Reverse num list:\n");
    TraverseList(num, shownum);



    /*转置偶数结点*/
     ReverseEvenList(&num);
     printf("Here is the ReverseEvenlist:\n");
     TraverseList(num, shownum);


    /*查找中间结点*/
    LinkedList pt;
    pt=FindMidNode(&num);
    if(pt!=num)
        printf("\nThe mid node's num is %d\n\n",pt->data);
    else
        printf("\nNo mid node.\n");



    /*判断是否成环*/
    if(IsLoopList(num)==ERROR)
        printf("The num list is not loop list\n");
    else
        printf("The num list is a loop list\n");



    /*释放链表*/
    DestroyList(&num);
    getchar();
    getchar();

    return 0;
}

void shownum( ElemType e)
{
    printf("The data: %d\n",e);
}
