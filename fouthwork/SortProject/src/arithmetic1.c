#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<assert.h>
#include"LinkStack.c"
#include"../inc/LinkStack.h"


void insertSort(int *a,int n)
{
    int i, j;
    for(i=1; i<n; i++)
    {
        int t=a[i];
        for(j=i-1; j>-1&&a[j]>t; j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=t;
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{

    int i=begin, j=mid+1, k =begin;
    while(i!=mid+1 && j!=end+1)
    {
        if(a[i] > a[j])
            temp[k++] = a[j++];
        else
            temp[k++] = a[i++];
    }
    while(i!=mid+1)
        temp[k++]=a[i++];
    while(j!=end+1)
        temp[k++]=a[j++];
    for(i=begin; i<=end; i++)
        a[i] = temp[i];
}

void MergeSort(int *a,int begin,int end,int *temp)
{
    int mid;
    if(begin < end)
    {
        mid = begin+(end-begin)/2;
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid+1, end, temp);
        MergeArray(a, begin, mid, end, temp);
    }
}

void MergeTest(int *a, int n)
{

    int *p = NULL;
    if((p=(int *)malloc(sizeof(int)*n)) == NULL)
    {
        printf("归并排序动态内存分配失败\n");
        printf("不能进行归并排序\n");
        return ;
    }
     MergeSort(a, 0, n, p);
    if(p != NULL)
        free(p);
}

void QuickSort_Recursion(int *a, int begin, int end)    //递归版
{
    if(begin>=end)
        return ;
    int left = begin;
    int right = end;
    int key = a[begin];
    while(begin<end)
    {
        while(a[end]>=key && begin<end)
            --end;
        a[begin]=a[end];
        while(a[begin]<=key && begin<end)
            begin++;
        a[end]=a[begin];
    }
    a[begin]=key;
    QuickSort_Recursion(a, left, end-1);
    QuickSort_Recursion(a, end+1, right);
}

void QuickSortTest_Recursion(int *a, int n)
{
    QuickSort_Recursion(a, 0, n);
}

int Partition(int *a, int begin, int end)
{
    int key=a[begin];
    while(begin < end)
    {
        while(begin<end && a[end]>=key)
            end--;
        a[begin] = a[end];
        while(begin<end && a[begin] <= key)
            begin++;
        a[end]=a[begin];
    }
    a[begin]=key;
    return begin;
}

void QuickSort(int *arr,int size)
{

	LinkStack s;
	int position;
	int left = 0;
	int right = size-1;
	initLStack(&s);
	pushLStack(&s, 0);
	pushLStack(&s, right);
	while (!isEmptyLStack(&s))
	{
		right = getTopLStack(&s);
		popLStack(&s);
		left=getTopLStack(&s);
		popLStack(&s);
		position = Partition(arr, left, right);
		//先快排基准左侧，则先将后侧的下标入栈
		if (position-1>left)
		{
			pushLStack(&s, left);
			pushLStack(&s, position-1);
		}
		if (position+1<right)
		{
			pushLStack(&s, position+1);
			pushLStack(&s, right);
		}
	}
}

void CountSort(int *a, int size , int max)
{
    int *b=NULL;
    int *c=NULL;
    if(((c=(int *)malloc(sizeof(int)*(max+1))) == NULL)
        || ((b=(int *)malloc(sizeof(int)*size)) == NULL))
    {
        printf(" 计数排序分配动态内存失败\n");
        return ;
    }
    int i;
    for(i=0; i<=max; i++)
        c[i]=0;
    for(i=0;i<size;i++)
        c[a[i]]++;
    for(i=1;i<=max;i++)
        c[i]=c[i]+c[i-1];
    for(i=size-1;i>=0;i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    for(i=0;i<size;i++)
        a[i]=b[i];

    if(b != NULL)
        free(b);
    if(c != NULL)
        free(c);
}

void RadixCountSort(int *a,int size)
{
    int maxlength(int *a, int size)
    {
        int bits=1, p=10, i;
        for(i=0; i<size; i++)
        {
            while(a[i]>=p)
            {
                p=p*10;
                bits++;
            }
        }
        return bits;
    }

    int getdigit(int num, int pos)
    {
        int temp=1, i;
        for(i=0; i<pos-1; i++)
            temp=temp*10;
        return (num/temp)%10;
    }

    int *bucket[10];
    int i;
    for(i=0; i<10; i++)
    {
        if((bucket[i]=(int *)malloc(sizeof(int)*(size+1)))==NULL)
        {
            printf("基数排序配置内存失败");
            return;
        }
        bucket[i][0]=0;
    }
    int bit;
    for(bit=1; bit<=maxlength(a,size); bit++)
    {
        for(i=0; i<size; i++)
        {
            int num=getdigit(a[i], bit);
            int index=++bucket[num][0];
            bucket[num][index]=a[i];
        }
        int index=0;
        for(i=0; i<10; i++)
        {
            int j;
            for(j=1; j<=bucket[i][0]; j++)
                a[index++] = bucket[i][j];
            bucket[i][0]=0;
        }
    }

    for(i=0; i<10; i++)
    {
        if(bucket[i] != NULL)
        free(bucket[i]);
    }
}
