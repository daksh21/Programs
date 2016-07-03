// Program to find palindrome using stack
// Author: Daksh Agarwal

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	char ch;
	struct node *next;
};
typedef struct node node;
node *top=NULL,*front=NULL,*rear=NULL;
void push(char str)
{
	node *t;
	t=(node*)malloc(sizeof(node));
	t->ch=str;
	if(top==NULL)
	{
		top=t;
		top->next=NULL;
	}
	else
		t->next=top;
	top=t;
}
int pop()
{
	char c;
	if(top==NULL)
	{
		printf("\nEmpty");
	}
	else
	{
		c=top->ch;
		top=top->next;

	}
	return c;
}
void enqueue(char str)
{
	node *t;
	t=(node*)malloc(sizeof(node));
	t->ch=str;
	t->next=NULL;
	if(front==NULL)
	{
		front=t;
		rear=t;
	}
	else
	{
		rear=front;
		while(rear->next!=NULL)
		{
			rear=rear->next;
		}
		rear->next=t;
		rear=rear->next;
	}
}
int dequeue()
{
	char c;
	if(front==NULL)
	{
		printf("\nEmpty");
	}
	else
	{
		c=front->ch;
		front=front->next;
	}
	return c;
}

void main()
{
	char a[20];
	int i=0,len=0;
	printf("\nenter the string:");
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		push(a[i]);
		enqueue(a[i]);
	}
	for(i=0;i<len;i++)
	{
		if(pop()!=dequeue())
			break;

	}

	if(i==len)
		printf("palindrome\n");
	else
		printf("not palindrome\n");
}

