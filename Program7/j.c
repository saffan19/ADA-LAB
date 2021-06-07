#include<stdio.h>
int right=1;
int left=0;
void swap(int*x ,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void displayArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int fact(int n)
{
    if(n==0)return 1;
    return n*fact(n-1);
}
int find_mobile_pos(int a[],int n,int mobile)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==mobile)return i;
    }
}
int find_mobile(int a[],int dir[],int n)
{
    int mobile=0,prev=0;
    for(int i=0;i<n;i++)
    {
        if(dir[a[i]]==0)//left
        {
            if(a[i]>prev&&a[i]>a[i-1])
            {
                prev=a[i];
                mobile=a[i];
                
            }
        }
        else //right
        {
            if(a[i]>prev&&a[i]>a[i+1])
            {
                prev=a[i];
                mobile=a[i];
                
            }
        }
    }
    return mobile;
}

void rev_direction(int a[],int n,int k,int dir[])
{
    for(int i=0;i<n;i++)
    {
        if(a[i]>k)
        {
            if(dir[a[i]]==0)dir[a[i]]=1;
            else
            dir[a[i]]=0;
        }
    }
}
void perm(int a[],int dir[],int n)
{
    int mobile_pos,k,num_perm,i,mobile;
    num_perm=fact(n);
    displayArray(a, n);
    for (i = 1; i < num_perm; i++)
    {
        
        
        mobile = find_mobile(a, dir, n);
        mobile_pos=find_mobile_pos(a,n,mobile);
        
        if (dir[a[mobile_pos]] == 1)
        {
            swap(&a[mobile_pos], &a[mobile_pos + 1]);
        }
        else{
            swap(&a[mobile_pos], &a[mobile_pos - 1]);
        }
        
        rev_direction(a, n, mobile,dir);
        displayArray(a, n);
        //displayArray(dir,n);
        
    }
}
void main()
{
    int n,a[1000];
    printf("Enter number of elements:\n");
    
    scanf("%d",&n);
    int dir[n];
    for(int i=0;i<n;i++)
    {
        a[i]=i;
        dir[i]=0;
    }
    perm(a,dir,n);
}