#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void delay(int milli_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
 void createArray(int a[],int n)
 {
     for(int i=0;i<n;i++)
        a[i]=rand()%1000;
 }
 void display(int a[],int n)
 {
     for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\n");
 }
 void sort(int a[],int n)
 {
     int temp;
     for(int i=1;i<n;i++)
     {
         for(int j=0;j<n-1-i;j++)
         {
             if(a[j]>a[j+1])
             {
                 temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
             }
         }
     }
 }

int linearSearch(int a[],int start,int end,int key)
{
    delay(1);
    if(start>end)return -1;
    if(a[start]==key)return start;
    return linearSearch(a,start+1,end,key);
    
}
int binarySearch(int a[],int start,int end,int key)
{
    delay(1);
    if(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==key)return mid;
        if(key<a[mid])return binarySearch(a,start,mid-1,key);
        return binarySearch(a,mid+1,end,key);
    }
    return -1;
}
/*
 int binarySearch(int a[],int start,int end,int key)
 {
     delay(1);
     int mid;
     if(start<=end)
     {
         mid=start+(end-start)/2;
         if(a[mid]==key)return mid;
         else if(key>a[mid])return binarySearch(a,mid+1,end,key);
         else
         return binarySearch(a,start,mid-1,key);
     }
     return -1;
 }
 */
 void main()
 {
     int n,a[50000],c=1,choice,key,pos;
     clock_t start,end;
     while(c==1)
     {
         printf("Enter size of array:\n");
         scanf("%d",&n);
         createArray(a,n);
         printf("Array is:\n");
         display(a,n);
         printf("Enter key to be searched:\n");
         scanf("%d",&key);
         printf("Linear Search:\n");
         start=clock();
         pos=linearSearch(a,0,n,key);
         end=clock();
         if(pos==-1)printf("Key not found!\n");
         else
         printf("Key found at position %d\n",pos+1);
         printf("Time taken for linear search: %f ms\n",(double)(end-start)/CLK_TCK*100);
         printf("--------------------\n");
         printf("Binary Search:\n");
         sort(a,n);
         display(a,n);
         start=clock();
         pos=binarySearch(a,0,n,key);
         end=clock();
         if(pos==-1)printf("Key not found!\n");
         else
         printf("Key found at position %d\n",pos+1);
         printf("Time taken for Binary search: %f ms\n",(double)(end-start)/CLK_TCK*100);
         printf("\n________________\n");
         printf("Press 1 to exit\nPress 2 to continue..\n");
         scanf("%d",&choice);
         if(choice==1)break;
         
     }
 }