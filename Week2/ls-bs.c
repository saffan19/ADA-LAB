#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void delay(int milli_seconds)
{
 
    clock_t start_time = clock();
  
    while (clock() < start_time + milli_seconds);
}
int rLinearSearch(int a[],int start,int end,int key)
{
    delay(10);
    if(start>end)return -1;
    if(a[start]==key)return start;
    //if(a[end]==key)return end;
    return rLinearSearch(a,start+1,end,key);
    
}
int rBinarySearch(int a[],int start,int end,int key)
{
    delay(10);
    if(start>end)return -1;
    int mid=(start+end)/2;
    if(a[mid]==key)return mid;
    if(key>a[mid])return rBinarySearch(a,mid,end,key);
    else
    return rBinarySearch(a,start,mid,key);
}
void sort(int a[],int n)
{
    int temp;
    for(int i=1;i<n-1;i++)
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
void createArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
}
void displayArray(int a[],int n)
{
    printf("Random array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void main()
{
    int n,choice,c=1,key,pos,a[1000],time;
    clock_t start,end;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    createArray(a,n);
    while(c==1)
    {

        printf("Enter choice:\n1)Linear Search\n2)Binary Search\n3)Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                
                displayArray(a,n);
                printf("Enter key:\n");
                scanf("%d",&key);
                start=clock();
                pos=rLinearSearch(a,0,n,key);
                end=clock();
                if(pos==-1)printf("Element Not Found\n");
                else{
                    printf("Element found at position %d\n",pos+1);
                }
                printf("Time taken: %f ms\n",(double)(end-start)/CLK_TCK*1000);
                break;
            case 2:
                
                sort(a,n);
                displayArray(a,n);
                printf("Enter key:\n");
                scanf("%d",&key);
                start=clock();
                pos=rBinarySearch(a,0,n,key);
                end=clock();
                if(pos==-1)printf("Element Not Found\n");
                else{
                    printf("Element found at position %d\n",pos+1);
                }
                printf("Time taken: %f ms\n",(double)(end-start)/CLK_TCK*1000);
                break;
            case 3:
                c=0;break;
            default:
            printf("Invalid input!Try again.\n");
        }
    }
}