#include "../head/SqStack.h"
#include"SqStack.c"
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
char get_choice(void);
int get_ElemType(void);
char get_first(void);

int main(void)
{
    ElemType e;
    SqStack s;
    char choice;
    int length;
    initStack(&s,SIZE);
    while((choice=get_choice())!='q')
    {
        switch(choice)
        {
            case 'a':if(initStack(&s,SIZE) == SUCCESS)
                        printf("Congratulation! Initialization was successful.\n");
                    else
                        printf("Sorry, Initialization was failing.\n");
                    break;
            case 'b':if(isEmptyStack(&s))
                        printf("The Stack is empty.\n");
                    else
                        printf("The Stack is not empty.\n");
                    break;
            case 'c':if(getTopStack(&s,&e) == SUCCESS)
                        printf("Data at the top of the stack is %d.\n",e);
                    else
                        printf("Sorry,the Stack is empty.\n");
                    break;
            case 'd':if(clearStack(&s) == SUCCESS)
                        printf("The Stack has been cleared.\n");
                    else
                        printf("The Stack is empty.\n");
                    break;

            case 'e':if(destroyStack(&s) == SUCCESS)
                    {
                        printf("The Stack has been destroyed.\n");
                        printf("Bye!");
                        exit(1);
                    }
                    break;
            case 'f':if(stackLength(&s,&length) == SUCCESS)
                        printf("The length of the stack is %d.\n",length);
                    break;
            case 'g':printf("Please input the data you want to save: ");
                     e = get_ElemType();
                     if(pushStack(&s,e) == SUCCESS)
                        printf("\nGood! operate successfully.\n");
                     else
                        printf("\nSorry! operate failure.\n");
                    break;
            case 'h':if(popStack(&s,&e) == SUCCESS)
                        {
                            printf("Good! operate successfully.\n");
                            printf("The data is %d.\n",e);
                        }
                    else
                        printf("Sorry! operate failure.\n");
                    break;

        }
    }
    printf("Bye.\n");
    getchar();
    getchar();
    return 0;
}

char get_choice(void)
{
    char ch;
    printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    printf("Enter the operation of your choice:\n");
    printf("%-36s%s\n","a.initStack","b.isEmptyStack");
    printf("%-36s%s\n","c.getTopStack","d.clearStack");
    printf("%-36s%s\n","e.destroyStack","f.stackLength");
    printf("%-36s%s\n","g.pushStack","h.popStack");
    printf("q.quit\n");
     printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    ch=get_first();
    while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'
          &&ch!='e'&&ch!='f'&&ch!='g'&&ch!='h'&&ch!='q')
    {
        printf("Please enter a ~ h or q.\n");
        ch=get_first();
    }
    return ch;
}

int get_ElemType(void)
{
    ElemType input;
    char ch;
    while(scanf("%d",&input)!=1)
    {
        while((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not a ElemType.\n");
        printf("Please enter a ElemType,such as 1 , 2 or 3: ");
    }
    while(getchar()!='\n')
        continue;
    return input;
}

char get_first(void)
{
    char ch;
    ch=getchar();
    while(getchar()!='\n')
        continue;
    return ch;
}

