#include<stdio.h>
int vis[10],n,a[10][10];
void bfs(int);
void main()
{
    int i,j,src;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the source node:\n");
    scanf("%d",&src);
    printf("All possible nodes reachable from node %d are:\n",src);
    bfs(src);    
}
void bfs(int v)
{
    int q[10],f=0,r=0,u,i;
    vis[v]=1;
    q[r]=v;
    while(f<=r)
    {
        u=q[f];
        printf("%d\t",u);
        for(i=0;i<n;i++)
        {
            if(a[u][i]==1 &&vis[i]==0)
            {
                vis[i]=1;
                r=r+1;
                q[r]=i;

            }
        }
        f++;
    }
}