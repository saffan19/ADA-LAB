#include<stdio.h>
int m,i,j,n,p[10],w[10],v[10][10],x[10],op_solu;
int max(int a,int b)
{
    return(a>b?a:b);
}
int knapsack()
{
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||m==0)
            {
                v[i][j]=0;
            }
            else
            {
                if(w[i]>j)
                {
                    v[i][j]=v[i-1][j];
                }
                else
                {
                    v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
                }
            }
        }
    }
    return v[i-1][j-1];
}
void object_selected()
{
    i=n;j=m;
    while(i!=0&&j!=0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    printf("Objects Selected:\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            printf("%d  ",i);
        }
    }
}
void main()
{
    printf("Enter number of objects:\n");
    scanf("%d",&n);
    printf("Enter weights of N objects:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("Enter profits of N objects:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter capacity of knapsack:\n");
    scanf("%d",&m);
    op_solu=knapsack();
    printf("Matrix obtained:\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d   ",v[i][j]);
        }
        printf("\n");
    }
    printf("Optimum Solution: %d \n",op_solu);
    object_selected();
}