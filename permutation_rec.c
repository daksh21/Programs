// Program to permute with recursion
// Author: Daksh Agarwal

#include<stdio.h>
#include<time.h>
int main()
{
	int a[10],n,i,count=1;
	printf("enter the number:");
	scanf("%d",&n);
	clock_t t;
	t=clock();
	for(i=0;i<n;i++)
	{
		a[i]=count++;
	}
	permute(a,0,n-1);
	t=clock()-t;
	double time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\n permute() took %f second to execute \\n",time_taken);
	return 0;
}
void permute(int *a,int i,int n)
{
	int j,k;
	if(i==n)
	{
		for(k=0;k<=n;k++)
		{
			printf("%d",a[k]);
		}
		printf("\n");
	}	
	else
	{
		for(j=i;j<=n;j++)
		{
			swap(a+i,a+j);
			permute(a,i+1,n);
			swap(a+i,a+j);			
		}
	}
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
