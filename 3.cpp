#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#define infinity 999
int main()
{
int n,cost[10][10],distance[10],min,visited[10],u;
int i,j,source,sum;
//clrscr();
printf("\n enter the number of nodes:");
scanf("%d",&n);
printf("\n enter the cost matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&cost[i][j]);
printf("\n enter the source node:");
scanf("%d",&source);
printf("\n finding the shortest path:");
for(i=1;i<=n;i++)
{
distance[i]=cost[source][i];
visited[i]=0;
}
visited[source]=1;
for(i=1;i<=n;i++)
{
min=infinity;
for(j=1;j<=n;j++)
if(visited[j]==0 && distance[j]<min)
{min=distance[j];
u=j;
}
visited[u]=1;
for(j=1;j<=n;j++)
if(visited[j]==0 && (distance[u]+cost[u][j]<=distance[j]))
{
distance[j]=distance[u]+cost[u][j];
}
}
for(i=1;i<=n;i++)
printf("\nshorest path from %d to %d is %d",source,i,distance[i]);
getch();
}