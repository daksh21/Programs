// Program to implement Floyd algorithm
// Author: Daksh Agarwal

#include<stdio.h>
#define Inf 999
void floyd(int a[10][10],int n);
void display(int dist[10][10],int n);
void printpath(int dist[10][10],int n,int pre[10][10]);
void main()
{
	int a[10][10],i,j,n;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the values for %d row\n",i);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	floyd(a,n);
}
void floyd(int a[10][10],int  n)
{
	int i,j,k,dist[10][10],pre[10][10];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dist[i][j]=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			pre[i][j]=j;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					pre[i][j]=pre[i][k];
				}
			}
		}
	}
	display(dist,n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",pre[i][j]);
		}
		printf("\n");
	}
	printpath(dist,n,pre);
}
void display(int dist[10][10],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	        for(j=1;j<=n;j++)
		{
			if(dist[i][j]==999)
				printf("%s\t","Inf");
			else
				printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}
}
void printpath(int dist[10][10],int n,int pre[10][10])
{
	int i,j,pt;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nThe shortest path from <%d,%d> :",i,j);
			pt=i;
			printf("%d",pt);
			while(pt!=j)
			{
				pt=pre[pt][j];
				printf("-->%d",pt);
			}
		}
	}
	printf("\n");
			
}
