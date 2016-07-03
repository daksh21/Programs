// Program to implement Monte-Carlo
// Author: Daksh Agarwal

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mcarl(u) ((rand()/(double)RAND_MAX)*(u))
double area(int);
void main()
{
	int i,trial;
	do{
		printf("Run?(yes=1,no=0)\n");
		scanf("%d",&i);
		if(i)
		{
			printf("how many trials:\n");
			scanf("%d",&trial);
			printf("%f\n",area(trial));
		}
	}while(i);
}
double area(int trial)
{
	double x,y;
	int k,hit=0;
	for(k=0;k<trial;k++)
	{
		x=mcarl(1.0);
		y=mcarl(1.0);
		if(y<=exp(-x*x/2))
			hit++;
	}
	return (double)hit/trial;
}
