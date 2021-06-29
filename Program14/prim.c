#include<stdio.h>
int cost[10][10],vis[10],vt[10],et[10][10],e=0,i,j,k,u,v,sum=0,n,m;

void prims()
{
    int x=1,min;
    vt[x]=1;
    vis[x]=1;
    for(i=1;i<n;i++)
    {
        j=x;
        min=999;
        while(j>0)
        {
            k=vt[j];
            for(m=2;m<=n;m++)
            {
                if(cost[k][m]<min&&vis[m]==0)
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
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost of adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    }
    prims();
    printf("Minimum Spanning Tree:\n");
    for(i=1;i<=n;i++)
    {
        if(et[i][1]!=0&&et[i][2]!=0)
            printf("%d  %d\n",et[i][1],et[i][2]);
    }    
    printf("Total Cost =%d",sum);
}