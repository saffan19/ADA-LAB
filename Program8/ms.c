#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void merge(int a[], int low,int mid,int high)

{
    int i, j, k, c[50000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i <= mid)
        c[k++]=a[i++];

    while(j<=high)
        c[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=c[i];
}

void merge_sort(int a[], int low, int up)
{
    if (low < up)
    {
        int mid = (low + up) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, up);
        merge(a, low, mid, up);
    }
}
void main()
{
    int a[50000], n;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    createArray(a, n);
    printf("Before sorting:\n");
    displayArray(a, n);
    clock_t start, end;
    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();
    printf("After sorting:\n");
    displayArray(a, n);
    printf("Time taken:%f microseconds\n", (double)(end - start) / (CLK_TCK)*100000);
}