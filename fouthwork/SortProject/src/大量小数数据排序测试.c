#include"../inc/qgsort.h"
#include"arithmetic1.c"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#define NUM 100000
#define SIZE 100
#define MAX 10
void Initiate(int *p, int *q, int n);
void Random(int *p, int n, int a, int b);
int main(void)
{
    int *arr[NUM] = {NULL};
    int *brr[NUM] = {NULL};
    int i;
    clock_t start, finish;
    double  duration;
    for(i=0; i<NUM; i++)
    {
         if(((arr[i]=(int *)malloc(sizeof(int)*SIZE)) == NULL)
        || ((brr[i]=(int *)malloc(sizeof(int)*SIZE)) == NULL))
        {
            printf(" Sorry, the application failed to allocate memory.\n");
            system("pause");
            return 0;
        }
        Random(arr[i], SIZE, MAX, 0);
    }

    printf("100数据*100k次排序用时：\n");
    //插入排序
    for(i=0; i<NUM; i++)
    {
        Initiate(arr[i], brr[i], SIZE);
    }

    start = clock();
    for(i=0; i<NUM; i++)
    {
        insertSort(brr[i], SIZE);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("插入排序用时： %f seconds\n", duration);


    //归并排序
    for(i=0; i<NUM; i++)
    {
        Initiate(arr[i], brr[i], SIZE);
    }
    start = clock();
    for(i=0; i<NUM; i++)
    {
         MergeTest(brr[i], SIZE);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("归并排列序用时： %f seconds\n", duration);

    //快速排序递归版
    for(i=0; i<NUM; i++)
    {
        Initiate(arr[i], brr[i], SIZE);
    }
    start = clock();
    for(i=0; i<NUM; i++)
    {
         QuickSortTest_Recursion(brr[i], SIZE);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("快速排序递归版用时： %f seconds\n", duration);

       //快速排序非递归版
    for(i=0; i<NUM; i++)
    {
        Initiate(arr[i], brr[i], SIZE);
    }
    start = clock();
    for(i=0; i<NUM; i++)
    {
         QuickSort(brr[i],SIZE);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("快速排序非递归版： %f seconds\n", duration);


     //计数排序
    for(i=0; i<NUM; i++)
    {
        Initiate(arr[i], brr[i], SIZE);
    }
    start = clock();
    for(i=0; i<NUM; i++)
    {
          CountSort(brr[i], SIZE, MAX);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("计数排序用时： %f seconds\n", duration);

    //基数排序
    for(i=0; i<NUM; i++)
    {
        Initiate(arr[i], brr[i], SIZE);
    }
    start = clock();
    for(i=0; i<NUM; i++)
    {
          RadixCountSort(brr[i], SIZE);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("基数排序用时： %f seconds\n", duration);

    if(arr != NULL)
                free(arr);
    if(brr != NULL)

    system("pause");
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
void Initiate(int *p, int *q, int n)
{
    int i;
    for(i=0; i<n; i++)
        q[i]=p[i];
}
