// Program to implement counting sort
// Author: Daksh Agarwal

#include<stdio.h>
#define range_of_num 200
#define size 40
void main()
{
	int a[size],b[size],c[range_of_num],i,j,k,num;
	printf("Enter the number of terms:\n");
	printf("Enter the range of numbers:\n");
	scanf("%d%d",&num,&k);
	printf("Enter the numbers in the array:\n");
	for(i=1;i<=num;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=k;i++)
		c[i]=0;//c[0....k] provides the temporary working storage. 
	for(j=1;j<=num;j++)
		c[a[j]]=c[a[j]]+1;//c[i] now contains the no. of elements equal to i.
	for(i=2;i<=k;i++)
		c[i]=c[i]+c[i-1];//c[i] now contain the no. of elements less then or equal to i.
	for(i=1;i<=num;i++)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]=c[a[i]]-1;
	}
	printf("Sorted array is: \n");
	for(i=0;i<num;i++)
		printf("%d\t",b[i]);//b[1...n] will holds the sorted output.
	printf("\n");
}
