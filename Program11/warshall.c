#include<stdio.h>
int a[10][10],n,p[10][10];
void warshall()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            p[i][j]=a[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(p[k][i]==1&&p[i][j]==1&&p[k][j]!=1)p[k][j]=1;
            }
        }
    }
    printf("Path  Matrix is:\n");
    printf("   ");
    for(i=0;i<n;i++)printf("%d ",i);
    printf("\n");
    printf("   ");
    for(i=0;i<n;i++)printf("- ");
    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("%d |",i);
        for(j=0;j<n;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    warshall();
}