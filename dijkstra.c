// Program to implement Dijkstra Algorithm
// Author: Daksh Agarwal

#include<stdio.h>
#define infinity 1000
void djk(int n,int v,int cost[10][10],int d[10])
{
	int i,count=2,flag[10],min,x,y;

	for(i=1;i<=n;i++)
	{
		flag[i]=0;
		d[i]=cost[v][i];
	}
	while(count<=n)
	{
		min=99;
		for(y=1;y<=n;y++)
			if(min>d[y] && !flag[y])
			{
				min=d[y];
				x=y;
			}
		flag[x]=1;
		count++;
		for(y=1;y<=n;y++)
			if((d[x]+cost[x][y]<d[y]) && !flag[y])
				d[y]=d[x]+cost[x][y];
	}
}
void main()
{
	int n,v,i,j,cost[10][10],d[10];
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the cost matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=infinity;
		}
	}	
	printf("Enter the source vertex:\n");
	scanf("%d",&v);
	djk(n,v,cost,d);
	printf("Shortest path:\n");
	for(i=1;i<=n;i++)
		if(i!=v)
			printf("%d->%d,cost=%d\n",v,i,d[i]);

}
