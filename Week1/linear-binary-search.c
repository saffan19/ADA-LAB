#include<stdio.h>
#include<stdlib.h>
void bs();
void ls();
void main()
{
    int choice,c=1;
    while(c==1)
    {
        printf("Enter choice:\n1)Linear Seacrh\n2)Binary Search\n3)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:ls();break;
            case 2:bs();break;
            case 3:c=0;break;
            default:printf("Invalid choice!\n");
        }
    }
}
void ls()
{
    int a[15],key,pos,flag=0,i;
    for(i=0;i<15;i++)
    {
        a[i]=rand()%100;
    }
    printf("The list is :\n");
    for(i=0;i<15;i++)
    {
      printf("%d ",a[i]);  
    }

    printf("\nEnter the key to be searched:\n");
    scanf("%d",&key);
    for(i=0;i<15;i++)
    {
        if(a[i]==key)
        {
            pos=i+1;
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("Key not found!\n");
    }
    else
    {
        printf("Key found at position %d\n",pos);
    }

}
void bs()
{
    int a[15],pos,key,i,temp,j;
    for(i=0;i<15;i++)
    {
        a[i]=rand()%100;
    }
    for(i=0;i<15;i++)
    {
        
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
        
    }
    printf("The sorted list is:\n");
    for(i=0;i<15;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nEnter key to be searched:\n");
    scanf("%d",&key);
    int low=0,high=14,mid,flag=0;
    while(low<=high&& flag==0)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            flag=1;
        }
        if(key>a[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==0)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Key found at position %d\n",mid+1);
    }
}