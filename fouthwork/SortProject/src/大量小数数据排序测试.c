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

    printf("100����*100k��������ʱ��\n");
    //��������
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
    printf("����������ʱ�� %f seconds\n", duration);


    //�鲢����
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
    printf("�鲢��������ʱ�� %f seconds\n", duration);

    //��������ݹ��
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
    printf("��������ݹ����ʱ�� %f seconds\n", duration);

       //��������ǵݹ��
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
    printf("��������ǵݹ�棺 %f seconds\n", duration);


     //��������
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
    printf("����������ʱ�� %f seconds\n", duration);

    //��������
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
    printf("����������ʱ�� %f seconds\n", duration);

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
