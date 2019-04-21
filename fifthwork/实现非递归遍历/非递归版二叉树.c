#include<stdio.h>
#include<stdbool.h>
#include"BinaryTree.h"
#include"BinaryTree_nonrec.c"
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
                     printf("���Ѿ�����������ˣ���Ҫ���¹������������١�");
                     break;
                }
                printf("�������ַ���������#��ʾ���������Ի��н�����:\n");
                s_gets(str, MAX);
                while(!check_str(str))
                {
                    printf("����������������������:\n");
                    s_gets(str, MAX);
                }
                if(CreateBiTree(&T, str) == SUCCESS)
                    printf("��ã������������ɹ���");
                flag = true;
                break;
        case 'b':if(PreOrderTraverse(T, shownum) == ERROR)
                    printf("�Բ��𣬶�����Ϊ�ա�");
                break;
        case 'c':if(InOrderTraverse(T, shownum) == ERROR)
                    printf("�Բ��𣬶�����Ϊ�ա�");
                break;
        case 'd':if(PostOrderTraverse(T, shownum) == ERROR)
                    printf("�Բ��𣬶�����Ϊ�ա�");
                break;
        case 'e':DestroyBiTree(&T);
                printf("���ٶ������ɹ���\n");
                flag = false;
        }
    }
    DestroyBiTree(&T);
    printf("�ټ�");
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
    printf("%-36s%s\n","a.���������T","b.�������������T");
    printf("%-36s%s\n","c.�������������T","d.�������������T");
    printf("%-36s%s\n","e.�ݻٶ�����T","q.quit\n");
     printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    ch=get_first();
    while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'
          &&ch!='e'&&ch!='q')
    {
        printf("Please enter a ~ e or q.\n");
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
