// Program to find powerset of a set
// Author: Daksh Agarwal

#include <stdio.h>
#include <math.h>
int d[50],n;

void PowerSet(int d[50], int set_size)
{
	unsigned  int pow_set_size = pow(2, set_size);
	int count, j;


	for(count = 0; count < pow_set_size; count++)
	{
		for(j = 0; j < set_size; j++)
		{

			if(count & (1<<j))

				printf("%d",d[j]);
		}
		printf("\n");
	}
}


int main()
{

	int d[50],n,i;
	printf("enter the size of set");
	scanf("%d",&n);
	printf("enter the element of array");
	for(i=0;i<n;i++)
		scanf("%d",&d[i]);
	PowerSet(d, n);
	return 0;
}
