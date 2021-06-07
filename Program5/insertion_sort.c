#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void createArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
}
void displayArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void insertion_sort(int a[],int n)
{
    int i, num, j;
    for (i = 1; i < n; i++)
    {
        num = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > num)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = num;
    }
}
void main()
{
    int a[50000],n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    createArray(a,n);
    printf("Before sorting:\n");
    displayArray(a,n);
    clock_t start,end;
    start=clock();
    insertion_sort(a,n);
    end=clock();
    printf("After sorting:\n");
    displayArray(a,n);
    printf("Time taken:%f ms\n", (double)(end-start)/(CLK_TCK)*100);
}