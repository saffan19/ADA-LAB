#include<stdio.h>
int a[10][10],p[10][10],n;
int min(int a,int b)
{
    if(a<b)return a;
    return b;
}
void floyd()
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
                p[j][k]=min(p[j][k],p[j][i]+p[i][k]);    
            }
        }
    }

    printf("Distance matrix:\n");
        printf("   ");
    for(int i=0;i<n;i++)printf("%d ",i);
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
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    floyd();

}