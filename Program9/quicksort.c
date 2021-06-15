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
int partition(int a[], int low, int high)
{
    int i, j, temp, pivot;
    pivot=a[low];
    i = low + 1;
    j = high;
    while (i <= j)
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)  
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quick_sort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        quick_sort(a, low, mid - 1);
        quick_sort(a, mid + 1, high);
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
    quick_sort(a, 0, n - 1);
    end = clock();
    printf("After sorting:\n");
    displayArray(a, n);
    printf("Time taken:%f microseconds\n", (double)(end - start) / (CLK_TCK)*100000);
}