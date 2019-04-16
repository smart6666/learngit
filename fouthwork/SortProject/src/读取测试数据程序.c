#include"../inc/qgsort.h"
#include"arithmetic1.c"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define SIZE 10000
#define MAX 50
#define SLEN 81
char get_choice(void);
char get_first(void);
char* s_gets(char* st, int n);
void print(int *a, int size);

int main(void)
{
    FILE *fa;               //fp指向目标文件
    char file_app[SLEN];    //目标文件名
    int *arr;
    char choice;

    if((arr=(int *)malloc(sizeof(int)*SIZE)) == NULL)
        printf(" Sorry, the application failed to allocate memory.\n");


     while((choice=get_choice())!='q')
    {

        puts("Enter name of the file to be processed: ");
        s_gets(file_app, SLEN);
        if((fa = fopen(file_app, "rb")) == NULL)
        {
            printf("reverse can't open %s\n", file_app);
            exit(EXIT_FAILURE);
        }

        rewind(fa);

        for(int i=0; i<SIZE; i++)
        {
            fscanf(fa, "%d", &arr[i]);
        }printf("f");

        switch(choice)
        {
            case 'a': insertSort(arr, SIZE);
                    break;
            case 'b': MergeTest(arr, SIZE);
                    break;
            case 'c':QuickSortTest_Recursion(arr, SIZE);
                    break;
            case 'd': QuickSort(arr,SIZE);
                    break;
            case 'e': CountSort(arr, SIZE, MAX);
                    break;
            case 'f':RadixCountSort(arr, SIZE);
        }
        print(arr, SIZE);

        fclose(fa);

    }
    if(arr != NULL)
    free(arr);
    printf("Bye!\n");
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
    printf("Please enter algorithm you want to select: \n");
    printf("%-36s%s\n","a.插入排序","b.归并排序");
    printf("\n%-36s%s\n","c.快速排序递归版","d.快速排序非递归版");
    printf("\n%-36s%s\n","e.计数排序","f.基数排序");
    printf("\n%-36s\n","q.退出程序");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    ch=get_first();
    while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'
          &&ch!='e'&&ch!='f'&&ch!='q')
    {
        printf("Please enter a ~ c or q.\n");
        ch=get_first();
    }
    return ch;
}
void print(int *a, int size)
{
    for(int i=0; i<size; i++)
    {
        if(i%20==0)
            printf("\n");
        printf("%4d ",a[i]);
    }
}
