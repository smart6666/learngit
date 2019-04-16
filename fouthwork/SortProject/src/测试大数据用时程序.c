#include"../inc/qgsort.h"
#include"arithmetic.c"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#define MAX 10
char get_first(void);
char get_choice(void);
void Initiate(int *p, int *q, int n);
void print(int *a, int size);
void Random(int *p, int n, int a, int b);



int main(void)
{
    int *arr = NULL;
    int *brr = NULL;
    int n;
    char choice;
    while((choice = get_choice()) != 'q')
    {
        switch(choice)
        {
            case 'a': n=10000;break;
            case 'b': n=50000;break;
            case 'c': n=200000;break;
        }
        if(((arr=(int *)malloc(sizeof(int)*n)) == NULL)
        || ((brr=(int *)malloc(sizeof(int)*n)) == NULL))
            printf(" Sorry, the application failed to allocate memory.\n");
        else
        {
            Random(arr, n, MAX, 0);
            Initiate(arr, brr, n);
            insertSort(brr, n);
            Initiate(arr, brr, n);
            MergeTest(brr, n);
            Initiate(arr, brr, n);
            QuickSortTest_Recursion(brr, n);
            Initiate(arr, brr, n);
            QuickSort(brr,n);
            Initiate(arr, brr, n);
            CountSort(brr, n, MAX);
            Initiate(arr, brr, n);
            RadixCountSort(brr, n);

            if(arr != NULL)
                free(arr);
            if(brr != NULL)
                free(brr);
        }
    }
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
    printf("Please enter the amount of data you want to select: \n");
    printf("%-36s%s\n","a.10000","b.50000");
    printf("%-36s%s\n","c.200000","q.quit");
     printf("\n");
    for(int i=0;i<60;i++)
        printf("=");
    printf("\n");
    ch=get_first();
    while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='q')
    {
        printf("Please enter a ~ c or q.\n");
        ch=get_first();
    }
    return ch;
}


char get_first(void)
{
    char ch;
    ch=getchar();
    while(getchar()!='\n')
        continue;
    return ch;
}


void Initiate(int *p, int *q, int n)
{
    int i;
    for(i=0; i<n; i++)
        q[i]=p[i];
}

void print(int *a, int size)
{
    for(int i=0; i<size; i++)
    {
        if(i%30==0)
            printf("\n");
        printf("%d ",a[i]);
    }
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
