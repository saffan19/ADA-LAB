#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void createArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
}
void displayArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void heap_cons(int a[], int n)

{
    int i, j, k, item;
    for (k = 1; k < n; k++)
    {
        item = a[k];
        i = k;
        j = (i - 1) / 2;
        while (i > 0 && item > a[j])
        {
            a[i] = a[j];
            i = j;
            j = (i - 1) / 2;
        }
        a[i] = item;
    }
}
void heap_adj(int a[], int n)
{
    int i, j, item;
    j = 0;
    item = a[j];
    i = 2 * j + 1;
    while (i <= n - 1)
    {
        if(i + 1 <= n - 1)
        {
            if(a[i]<a[i+1])
                i++;
        }
        if(item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2 * j + 1;
        }
        else
            break;
    }
    a[j] = item;
}
void heap_sort(int a[], int n)
{
    int i,temp;
    heap_cons(a, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heap_adj(a, i);
    }
}

void main()
{
    int n, a[90000];
    clock_t start,end;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    createArray(a, n);
    //printf("Unsorted:\n");
    //displayArray(a, n);
    start=clock();
    heap_sort(a, n);
    end=clock();
    //printf("Sorted:\n");
    //displayArray(a, n);
    printf("TIME TAKES: %f microseconds\n",(double)(end-start)/CLK_TCK*100000);
}
