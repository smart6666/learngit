#include"tree_calculate.c"
#include"BinaryTree.h"
#define MAX 200
#include<stdio.h>
char* s_gets(char* st, int n);
char get_first(void);
char get_choice(void);
int main(void) {
    BiTree T;
    InitBiTree(&T);
    char choice;
    printf("请输入表达式(输入q退出):");
    while((choice=get_choice())!='q')
    {
        char a[MAX] = {0};
        printf("请输入表达式(输入q退出):");
        s_gets(a, MAX);
        CreateBiTree(&T, a);
        printf("Your result is %d\n",Value(T));
        DestroyBiTree(&T);
    }
    system("pause");
    return 0;
}

char get_first(void)
{
    char ch;
    ch=getchar();
    while(getchar()!='\n')
        continue;
    return ch;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    int i=0;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

char get_choice(void)
{
    char ch;
    printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    printf("Enter the operation of your choice:\n");
    printf("%-36s%s\n","a.计算前缀表达式","q.退出");
    printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    ch=get_first();
    while(ch!='a'&&ch!='q')
    {
        printf("Please enter a or q.\n");
        ch=get_first();
    }
    return ch;
}
