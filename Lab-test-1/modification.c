#include<stdio.h>

 void display(int a[],int n)
{
     for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\n");
}

int count=0;
int binarySearch(int a[],int start,int end,int key)
{
    int i;
    if(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==key)
        {
            count++;
            i=mid-1;
            while(a[i]==key&&i>0)
            {
                count++;
                i--;
            }
            i=mid+1;
            while(a[i]==key)
            {
                count++;
                i++;
            }
            return count;
        }
        if(key<a[mid])return binarySearch(a,start,mid-1,key);
        return binarySearch(a,mid+1,end,key);
    }
    return count;
}

void main()
{
    int a[]={1,2,3,3,3,3,4,5};
    int n=8,key;
    display(a,n);
    printf("Enter key:\n");
    scanf("%d",&key);
    printf("Mode of key %d is :%d\n",key,binarySearch(a,0,n,key));
    
}