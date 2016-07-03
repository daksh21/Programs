// Program to permute without using recursion
// Author: Daksh Agarwal

#include<stdio.h>
void main()
{
	int a[10],n,i,count=1,fac,k;
	printf("enter the number:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=count++;
	}
	fac=fact(n);
	for(i=0;i<fac;i++)
	{
		int j=i%(n-1);
		swap(a+j,a+j+1);
		for(k=0;k<n;k++)
		{
			printf("%d",a[k]);
		}
		printf("\n");

	}
}
int fact(int n)
{
	int i,fac=1;
	for(i=2;i<=n;i++)
	{
		fac=fac*i;
	}
	return fac;
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
