#include"../inc/qgsort.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#define SIZE 30
#define MAX 2
#define MIN 0

void print(int *a, int size);
void Random(int *p, int n, int a, int b);

int main(void)
{
    int *arr;
    if((arr=(int *)malloc(sizeof(int)*SIZE)) == NULL)
        printf(" Sorry, the application failed to allocate memory.\n");
    printf("原始数组为: \n");
    Random(arr, SIZE, MIN, MAX);
    print(arr, SIZE);
    ColorSort(arr, SIZE);
    printf("\n排序后数组为: \n");
    print(arr, SIZE);
    printf("\n");
    system("pause");
    return 0;
}

void swap(int *a, int i, int j)
{
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void ColorSort(int *a,int size)
{
    int i=0, j=0, k= size-1;
    for(i=0; i<=k; i++)
    {
        if(a[i] == 0)
         {
            swap(a, i, j);
            j++;
         }
         else if(a[i] == 2)
         {
             swap(a, i, k);
             k--;
             i--;
         }
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
void print(int *a, int size)
{
    for(int i=0; i<size; i++)
    {
        if(i%10==0)
            printf("\n");
        printf("%3d ",a[i]);
    }
}
