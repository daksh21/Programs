// Implement Fibonacci series
// Author: Daksh Agarwal

#include<stdio.h>
#include<time.h>
int n;
int main()
{
	printf("\n enter number of terms:");
	scanf("%d",&n);
	clock_t t;
	t=clock();
	fibo(n);
	t=clock()-t;
	double time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nfibo() took %f seconds to execute \n", time_taken);
	return 0;
}
int fibo(int num)
{
	if(num==0)
		return 0;
	else if(num==1)
		return 1;
	else
		return (fibo(num-1)+fibo(num-2));
}


