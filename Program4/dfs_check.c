#include<stdio.h>
int vis[10],a[10][10],n,count=0;
void dfs(int);
void main()
{
    int i,j,src;
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
        vis[i]=0;
    printf("Enter source vertex:\n");
    scanf("%d",&src);
    printf("Nodes reachable from vertex %d:\n",src);
    dfs(src);
    if(count==n)
    printf("\nAll nodes are connected\n");
    else
    printf("\nAll nodes are NOT connected\n");
}
void dfs(int v)
{
    int i;
    vis[v]=1;
    printf("%d ",v);
    count++;
    for(i=0;i<n;i++)
    {
        if(a[v][i]==1&&vis[i]==0)
        {
            dfs(i);
        }
    }
}
