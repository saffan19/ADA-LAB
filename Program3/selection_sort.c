#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milli_seconds)
{
 
    clock_t start_time = clock();
  
    while (clock() < start_time + milli_seconds);
}

void createArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
}
void displayArray(int a[],int n)
{
    //printf("Random array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void selection_sort(int a[],int n)
{
    int i,j,small_pos,temp;
    for(i=0;i<n-1;i++)
    {
        delay(1);
        small_pos=i;
        for(j=i+1;j<n;j++)
        {
            
            if(a[j]<a[small_pos])
            {
                small_pos=j;
            }
        }
        temp=a[i];
        a[i]=a[small_pos];
        a[small_pos]=temp;

    }
}




void main()
{
    int n, choice, c = 1;
    int a[2000];
    clock_t start, end;
    while (c == 1)
    {
        printf("Enter size:\n");
        scanf("%d", &n);
        createArray(a,n);
        printf("Random array:\n");
        displayArray(a,n);
        printf("1)Selection Sort\n2)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            start = clock();
            selection_sort(a,n);
            end = clock();
            printf("Array after sorting:\n");
            displayArray(a,n);
            printf("Time taken: %f ms\n", (double)(end - start) / CLK_TCK * 1000);
            break;
        case 2:c=0;break;
        default:printf("Invalid choice!\n");break;
        }
    }
}