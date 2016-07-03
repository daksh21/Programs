// Program to implement quick sort
// Author: Daksh Agarwal

#include<stdio.h>
void random(int arr[50]);
void quicksort(int arr[50],int,int);
int partition(int arr[50],int,int);
void swap(int *,int *);
void main()
{
	int arr[50],i;
	for(i=0;i<50;i++)
		arr[i]=i;
	random(arr);
	quicksort(arr,0,49);
	for(i=0;i<50;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
void random(int arr[50])
{
	int i,j,temp;
	srand(time(NULL));
	for(i=49;i>0;i--)
	{
		j=rand()%(i+1);
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}
void quicksort(int arr[50],int x,int y)
{
	int i;
	if(x<y)
	{
		i=partition(arr,x,y);
		quicksort(arr,x,i-1);
		quicksort(arr,i+1,y);
	}
}
int partition(int arr[50],int x,int y)
{
	int index=x+rand()%(y-x+1);
	int pivot;
	int i=x-1;
	int j;
	pivot=arr[index];
	swap(&arr[index],&arr[y]);
	for(j=x;j<y;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[y]);
	return i+1;
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
