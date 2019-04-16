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
void Random(int *p, int n, int a, int b);

int main(void)
{
    FILE *fa;               //fpָ��Ŀ���ļ�
    char file_app[SLEN];    //Ŀ���ļ���
    int *arr;
    char choice;

    if((arr=(int *)malloc(sizeof(int)*SIZE)) == NULL)
        printf(" Sorry, the application failed to allocate memory.\n");


     while((choice=get_choice())!='q')
    {

        puts("Enter name of destination file ");
        puts("(If you enter two identical file names,");
        puts("the data will be superimposed): ");
        s_gets(file_app, SLEN);
        if((fa = fopen(file_app, "a+")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", file_app);
            exit(EXIT_FAILURE);
        }

        Random(arr, SIZE, MAX, 0);
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
        for(int i=0; i<SIZE; i++)
        {
            if(i%30 == 0)
                fprintf(fa, "\n");
            fprintf(fa, "%d\t", arr[i]);
        }
        printf("����%s�ļ��ɹ�", file_app);
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
    printf("%-36s%s\n","a.��������","b.�鲢����");
    printf("\n%-36s%s\n","c.��������ݹ��","d.��������ǵݹ��");
    printf("\n%-36s%s\n","e.��������","f.��������");
    printf("\n%-36s\n","q.�˳�����");
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


void Random(int *p, int n, int a, int b)
{
    int max, min;
    if(a>b)
    {
        max=a-b+1;
        min=b;
    }
    else
    {
        max=b-a+1;
        min=a;
    }
    srand((unsigned int)time(NULL));
    for(int i=0; i<n; i++)
        {
            p[i]=rand()%max+min;
        }
}
