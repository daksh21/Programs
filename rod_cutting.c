// Rod cutting problem
// Author: Daksh Agarwal

#include<stdio.h>
#include<limits.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
int cutrod(int arr[20],int n)
{
	int i;
	int val=INT_MIN;
	for(i=0;i<n;i++)
		val=MAX(val,arr[i]+cutrod(arr,n-i-1));
	return val;
}
int main()
{
	int arr[20],i,n;
	printf("Enter the length:\n");
	scanf("%d",&n);
	printf("Enter the price for n lengths:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Maximum price would be:%d\n",cutrod(arr,n));
	return 0;
}
