#include<stdio.h>
#include<stdbool.h>
#include"BinaryTree.h"
#include"BinaryTree.c"
#define MAX 80
char* s_gets(char* st, int n);
char get_first(void);
char get_choice(void);
Status shownum( TElemType e);
bool check_str(char *str);
int main()
{
    int i;
    BiTree T;
    TElemType e1;
    InitBiTree(&T);
    char str[MAX];
    char choice;
    bool flag = false;
    while((choice=get_choice())!='q')
    {
        switch(choice)
        {
        case 'a':if(flag)
                {
                     printf("你已经构造二叉树了，若要重新构建，请先销毁。");
                     break;
                }
                printf("请输入字符串，符号#表示空子树，以换行建结束:\n");
                s_gets(str, MAX);
                while(!check_str(str))
                {
                    printf("您的输入有误，请重新输入:\n");
                    s_gets(str, MAX);
                }
                if(CreateBiTree(&T, str) == SUCCESS)
                    printf("你好，二叉树构建成功。");
                flag = true;
                break;
        case 'b':if(PreOrderTraverse(T, shownum) == ERROR)
                    printf("对不起，二叉树为空。");
                break;
        case 'c':if(InOrderTraverse(T, shownum) == ERROR)
                    printf("对不起，二叉树为空。");
                break;
        case 'd':if(PostOrderTraverse(T, shownum) == ERROR)
                    printf("对不起，二叉树为空。");
                break;
        case 'e':if(LevelOrderTraverse(T, shownum) == ERROR)
                    printf("对不起，二叉树为空。");
                break;
        case 'f':DestroyBiTree(&T);
                printf("销毁二叉树成功。\n");
                flag = false;
        }
    }
    DestroyBiTree(&T);
    printf("再见");
    system("pause");
    return 0;
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

char get_first(void)
{
    char ch;
    ch=getchar();
    while(getchar()!='\n')
        continue;
    return ch;
}

char get_choice(void)
{
    char ch;
    printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    printf("Enter the operation of your choice:\n");
    printf("%-36s%s\n","a.构造二叉树T","b.先序遍历二叉树T");
    printf("%-36s%s\n","c.中序遍历二叉树T","d.后序遍历二叉树T");
    printf("%-36s%s\n","e.层序遍历二叉树T","f.摧毁二叉树T");
    printf("q.quit\n");
     printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    ch=get_first();
    while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'
          &&ch!='e'&&ch!='f'&&ch!='q')
    {
        printf("Please enter a ~ f or q.\n");
        ch=get_first();
    }
    return ch;
}

Status shownum( TElemType e)
{
    printf("The data: %c\n",e);
    return SUCCESS;
}

bool check_str(char *str)
{
    char *a = str;
    int i=0,j=0;
    for(; *a!='\0'; a++)
    {
        if(*a == '#')
            i++;
        else
            j++;
        if(j < i-1)
            return false;
    }
    if(j != i-1)
        return false;
    return true;
}
