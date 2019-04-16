#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SIZE 20
#define MAX 500
#define MIN 0
int get_Integer(void);
int getMax(int *a, int n, int k);
void Random(int *p, int n, int a, int b);
void print(int *a, int size);

int main(void)
{
    int *arr;
    int k;
    int k_num;
    if((arr=(int *)malloc(sizeof(int)*SIZE)) == NULL)
        printf(" Sorry, the application failed to allocate memory.\n");
    Random(arr, SIZE, MIN, MAX);
    printf("原始数组如下: \n");
    print(arr, SIZE);
    printf("\n\n请输入您要的第k大数(0 ~ %d): ",SIZE);
    k=get_Integer();
    k_num=getMax(arr, SIZE, k);
    printf("\n第k大的数为： %d", k_num);
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

int random_partion(int *a, int n)
{
    int index = rand()%n;
    swap(a, index, n-1);
    int i=-1;
    int j=0;
    for(j=0; j<n; j++)
    {
        if(a[j]<a[n-1])
        {
            swap(a, ++i, j);
        }
    }
    swap(a, ++i, n-1);
    return i;
}

int getMax(int *a, int n, int k)
{
    int mid;
    if(k<=0)
        return -1;
    if(n<k)
        return -1;
    mid=random_partion(a, n);
    if(mid == n-k)
        return a[mid];
    else if(mid<n-k)
        getMax(a+mid+1, n-mid-1, k);
    else
        getMax(a, mid, k-(n-mid));
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
int get_Integer(void)
{
    int input;
    char ch;
    while(scanf("%d",&input)!=1 || input<=0 || input>SIZE)
    {
        while((ch=getchar())!='\n')
            putchar(ch);
        printf("you input is not a  positive Integer.\n");
        printf("Please enter a  positive Integer and <=SIZE,such as 1 , 2 or 3: ");
    }
    while(getchar()!='\n')
        continue;
    return input;
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
