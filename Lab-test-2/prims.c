#include<stdio.h>
int cost[10][10],vis[10],vt[10],et[10][2],u,v,e,n,sum=0;
void prims()
{
    int x=1;
    vt[x]=1;
    int min,k,m,j;
    for(int i=1;i<n;i++)
    {
        min=999;
        j=x;
        while(j>0)
        {
            k=vt[j];
            for(m=2;m<=n;m++)
            {
                if(cost[k][m]<min&&vis[m]==0&&cost[k][m]!=0)
                {
                    min=cost[k][m];
                    u=k;
                    v=m;
                }
            }
            j--;
        }
        vt[++x]=v;
        et[i][1]=u;
        et[i][2]=v;
        e++;
        vis[v]=1;
        sum=sum+cost[u][v];
    }
}
void main()
{
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    prims();
    printf("COST: %d",sum);
    printf("\nEdges selected:\n");
    for(int i=1;i<=e;i++)
    {
        printf("%d  -  %d\n",et[i][1],et[i][2]);
    }
}
