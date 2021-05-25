#include<stdio.h>
int a[10][10],indegree[10],n,flag[10];
void topological_order();
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
    printf("The topological order is:\n");
    topological_order();
}
void topological_order()
{
    int i,j,count=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indegree[i]=indegree[i]+a[j][i];
        }
    }
    while(count<n)
    {
        for(int k=0;k<n;k++)
        {
            if(indegree[k]==0 && flag[k]==0)
            {
                printf("%d ",k);
                flag[k]=1;
            }
            for(i=0;i<n;i++)
            {
                if(a[i][k]==1)
                    indegree[k]--;
            }
        }
        count++;
    }    

}