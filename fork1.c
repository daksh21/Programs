// Program to fork two processes
// Author: Daksh Agarwal

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int pid;
	if((pid=fork())==0)
	{
		if((pid=fork())==0)
		{
			if((pid=fork())==0)
				printf("Process 7\n");
			else
				printf("Process 4\n");
		}
		else
			printf("Process 2\n");
	}
	else if((pid=fork())==0)
	{
		sleep(1);
		if((pid=fork())==0)
		{
			sleep(1);
			printf("Process 5\n");
		}
		else if((pid=fork()==0))
		{
			sleep(2);
			printf("Process 6\n");
		}
		else
			printf("Process 3\n");
	}
	else
		printf("Process 1\n");
sleep(5);
}
