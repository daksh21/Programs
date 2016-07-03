// Program to find common elements from two sets
// Author: Daksh Agarwal

#include<stdio.h>
void main()
{
	int a[50],b[50],c[50],i,j,k=0,n,m;
	printf("enter the size of array a and array b:");
	scanf("%d%d",&n,&m);
	printf("enter the elements for array a:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the elements for array b:");
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
				c[k]=a[i];
				k++;
			}
		}
	}
	if(k==0)
		printf("no common element");
	else
	{
		printf("Common elements are: \n");
		for(i=0;i<k;i++)
		{
			printf("%d\t",c[i]);
		}
	}

}
