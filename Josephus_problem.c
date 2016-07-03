// Program to implement Josephus Problem (execution of people from circle)
// Author: Daksh Agarwal

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
int josephus(int, node *);
node *head=NULL,*h=NULL;;
void main()
{
	int count=1,n,m;
	node *new;
	printf("enter the value of n:\n");
	scanf("%d",&n);
	printf("enter the value of m:\n");
	scanf("%d",&m);
	while(count<=n)
	{
		new=(node*)malloc(sizeof(node));
		new->data=count++;
		if(head==NULL)
		{
			head=new;
			new->next=head;
		}
		else
		{
			h=head;
			while(h->next!=head)
				h=h->next;
			h->next=new;
			new->next=head;
		}
	}
	printf("circular linkedlist is:\n");
	h=head;
	while(h->next!=head)
	{
		printf("%d->",h->data);
		h=h->next;
	}
	printf("%d",h->data);
	printf("\n");
	josephus(m,head);
}
int josephus(int m,node *front)
{
	node *f;
	int c=1;
	while(front->next!=front)
	{
		c=1;
		while(c!=m)
		{
			f=front;
			front=front->next;
			c++;
		}
		f->next=front->next;
		printf("%d->",front->data);
		front=f->next;
	}
	printf("\n");
	printf("Winner is:%d\n",front->data);
	return;

}
