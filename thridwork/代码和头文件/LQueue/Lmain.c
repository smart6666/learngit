#include"../head/LQueue.h"
#include"LQueue.c"
#include<stdio.h>
#include<stdlib.h>


char get_choice1(LQueue *Q, void **e);
char get_choice2(void);
void get_ElemType(void *e);
char get_first(void);

 int len=0;                         /*数据类型标志   */

int main(void)
{
    LQueue Q;
    void *e;
    char choice;

    b: ;
    while((choice=get_choice1(&Q, &e)) != 'q')
    {
        InitLQueue(&Q);
        while((choice=get_choice2()) != 'q')
        {
             switch(choice)
        {
            case 'a': DestoryLQueue(&Q);
                        free(e);
                        printf("You have successfully destroyed the Queue !\n");
                        goto b;

            case 'b':if(TraverseLQueue(&Q, LPrint));
                        else
                            printf("Sorry! the Queue is empty.\n");
                    break;

            case 'c':if(IsEmptyLQueue(&Q))
                        printf("The Queue is empty.\n");
                    else
                        printf("Sorry,the Queue is not empty.\n");
                    break;

            case 'd':if(GetHeadLQueue(&Q, e))
                    {
                        printf("The head num is ");
                        LPrint(e,len);
                    }
                    else
                        printf("The Queue is empty.\n");
                    break;

            case 'e':printf("The length of Queue is %d.\n",LengthLQueue(&Q));
                    break;

            case 'f':printf("Please input the data you want to save: ");
                     get_ElemType(e);
                     if(EnLQueue(&Q, e))
                        printf("Good! operate successfully.\n");
                    else
                         printf("\nSorry! operate failure.\n");
                    break;

            case 'g':if(DeLQueue(&Q))
                        printf("\nGood! operate successfully.\n");
                     else
                        printf("\nSorry! operate failure.\n");
                    break;
            case 'h':ClearLQueue(&Q);
                     printf("You have cleared the Queue.\n");
                     break;

        }
        }
    }
    printf("Bye.\n");
    getchar();
    getchar();
    return 0;

}

char get_choice1(LQueue *Q, void **e)
{
    char ch;
    int i;
    for( i=0; i<30; i++)
        printf("**");
    printf("\n");
    printf("Welcome to the AQueue !  Now start to Initialize: \n");
    printf("Please input the type you want to use: \n");
    printf("%-26s%s\n\n","a.int","b.char");
    printf("%-26s%s\n","c.double","q.quit");
    for(i=0; i<30; i++)
        printf("**");
    printf("\n");
    ch = get_first();
    while(ch!='a' && ch!='b' && ch!='c' && ch!='q')
    {
       printf("Please enter a ~ c or q.\n");
        ch=get_first();
    }
     switch(ch)
    {
        case 'a': len=Q->length = 4;
        *e=(void*)malloc(Q->length);
                    break;
        case 'b': len=Q->length = 1;
        *e=(void*)malloc(Q->length);
                    break;
        case 'c': len=Q->length = 8;
        *e=(void*)malloc(Q->length);
                    break;
    }
    return ch;
}

char get_choice2(void)
{
    char ch;
    printf("\n");
    int i;
    for(i=0; i<60; i++)
        printf("=");
    printf("\n");
    printf("Enter the operation of your choice:\n");
    printf("%-36s%s\n","a.DestoryLQueue","b.TraverseLQueue");
    printf("%-36s%s\n","c.IsEmptyLQueue","d.GetHeadLQueue");
    printf("%-36s%s\n","e.LengthALueue","f.EnLQueue");
    printf("%-36s%s\n","g.DeLQueue","h.ClearLQueue");
    printf("q.quit\n");
     printf("\n");
    for(i=0;i<60;i++)
        printf("=");
    printf("\n");
    ch=get_first();
    while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'
          &&ch!='e'&&ch!='f'&&ch!='g'&&ch!='h'
          &&ch!='q')
    {
        printf("Please enter a ~ i or q.\n");
        ch=get_first();
    }
    return ch;
}

void get_ElemType(void *e)
{
    char ch;
    int AScanf(void *e)
    {
    switch(len)
    {
        case 1: if(scanf("%c", e) != 1)
                return 0;
                return 1;
                break;
        case 4: if(scanf("%d", e) != 1)
                return 0;
                return 1;
                break;
        case 8: if(scanf("%lf", e) != 1)
                return 0;
                return 1;
                break;
    }
    }
    while(AScanf(e)!=1)
    {
        while((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not the correct data.\n");
        printf("Please enter a correct data: ");
    }
    while(getchar()!='\n')
        continue;
}

char get_first(void)
{
    char ch;
    ch=getchar();
    while(getchar()!='\n')
        continue;
    return ch;
}
