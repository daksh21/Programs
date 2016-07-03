// Knapsack problem (0-1) implementation
// Author: Daksh Agarwal

#include<stdio.h>
void knapsack(int n,float wgt[20],float profit[20],float capacity);

int main()
{
	float wgt[20],profit[20],ratio[20],temp,capacity;
	int i,j,num;
	printf("enter the no. of object:-");
	scanf("%d",&num);
	printf("enter the weight and profit of each object:-");
	for(i=0;i<num;i++)
		scanf("%f%f",&wgt[i],&profit[i]);
	printf("enter the capacity of knapsac:-");
	scanf("%f",&capacity);
	for(i=0;i<num;i++)
		ratio[i]=profit[i]/wgt[i];
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;

				temp=wgt[j];
				wgt[j]=wgt[i];
				wgt[i]=temp;

				temp=profit[j];
				profit[j]=wgt[i];
				profit[i]=temp;
			}
		}
	}
	knapsack(num,wgt,profit,capacity);
	return(0);
}
void knapsack(int n, float wgt[],float profit[],float capacity)
{
	float x[20],tp=0;
	int i,j,c;
	c= capacity;
	for(i=0;i<n;i++)
		x[i] = 0.0;
	for(i=0;i<n;i++)
	{
		if(wgt[i]>c)
			break;
		else
		{
			x[i]=1.0;
			tp=tp+profit[i];
			c=c-wgt[i];
		}
	}
	if(i<n)
		x[i]=c/wgt[i];
	tp=tp+(x[i]*profit[i]);
	printf("\nthe result vector is:-");
	for(i=0;i<n;i++)
		printf("%f\t",x[i]);
	printf("\nmaximum profit is:- %f",tp);
}



