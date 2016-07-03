// Program to calculate set difference A-B and B-A
// Author: Daksh Agarwal

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[20],b[20],c[50],i,j,k=0,m,n,flag,p;
	printf("enter the size of arrays a,b:");
	scanf("%d %d\n",&n,&m);
	printf("enter the elements of array a:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the elements of array b");
	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if(flag==0)
		{
			c[k]=a[i];
			k++;
		}
	}
	p=k;
	printf("set difference (A-B) is :\n");
	for(k=0;k<p;k++)
		printf("%d",c[k]);

	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			if(b[j]==a[i])
			{
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if(flag==0)
		{
			c[k]=b[j];
			k++;
		}
	}
	p=k;
	printf("set difference (B-A) is :\n");
	for(k=0;k<p;k++)
		printf("%d",c[k]);

}
