// Program to implement Binary Search Tree
// Author: Daksh Agarwal

#include<stdio.h>
struct node{
	int value;
	struct node *left,*right;
};
typedef struct node node;
node *root=NULL,*temp=NULL,*t1=NULL;
void insert()
{
	int data;
	printf("enter a node to insert:\n");
	scanf("%d",&data);
	temp=(node*)malloc(sizeof(node));
	temp->value=data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
		insert1(root);
}
void insert1(node *n)
{
	if((temp->value>=n->value)&&(n->right!=NULL))
		insert1(n->right);
	else if((temp->value>=n->value)&&(n->right==NULL))
		n->right=temp;
	else if((temp->value<n->value)&&(n->left!=NULL))
		insert1(n->left);
	else if((temp->value<n->value)&&(n->left==NULL))
		n->left=temp;
}
void delete()
{
	int data;
	printf("enter the node to delete:\n");
	scanf("%d",&data);
	if(root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	t1=root;
	delete1(root,data);
}
void delete1(node *n,int data)
{
	if(data>n->value)
	{
		t1=n;
		delete1(n->right,data);
	}
	else if(data<n->value)
	{
		t1=n;
		delete1(n->left,data);
	}
	else if(data==n->value)
		delete2(n);
}
void delete2(node *n)
{
	if((n->left==NULL)&&(n->right==NULL))
	{
		if(t1->left==n)
			t1->left=NULL;
		else
			t1->right=NULL;
		n=NULL;
		free(n);
		return;
	}
	else if(n->right==NULL)
	{
		if(t1==n)
		{
			root=n->left;
			t1=root;
		}
		else if(t1->left==n)
			t1->left=n->left;
		else if(t1->right==n)
			t1->right=n->left;
		n=NULL;
		free(n);
		return;
	}

	else if(n->left==NULL)
	{
		if(t1==n)
		{
			root=n->right;
			t1=root;
		}
		else if(t1->left==n)
			t1->left=n->right;
		else if(t1->right==n)
			t1->right=n->right;
		n=NULL;
		free(n);
		return;
	}
	else if((n->left!=NULL)&&(n->right!=NULL))
	{
		int k;
		if(n->left!=NULL)
		{
			node *n1=n->left;
			while(n1->right!=NULL)
				n1=n1->right;
			k=n1->value;
		}
		else
		{
			node *n2=n->right;
			while(n2->left!=NULL)
				n2=n2->left;
			k=n2->value;
		}
		delete1(root,k);
		n->value=k;
	}
}
void search(int data,node *n)
{
	if(n==NULL)
		printf("node does not exist\n");
	else if(n->value==data)
		printf("node found\n");
	else if(n->value>data)
		search(data,n->left);
	else if(n->value<data)
		search(data,n->right);
}
void preorder(node *n)
{
	if(root==NULL)
		printf("Tree is empty\n");
	printf("%d\t",n->value);
	if(n->left!=NULL)
		preorder(n->left);
	if(n->right!=NULL)
		preorder(n->right);
	
}
void inorder(node *n)
{
	if(root==NULL)
		printf("Tree is empty\n");
	if(n->left!=NULL)
		inorder(n->left);
	printf("%d\t",n->value);
	if(n->right!=NULL)
		inorder(n->right);
}
void postorder(node *n)
{
	if(root==NULL)
		printf("Tree is empty\n");
	if(n->left!=NULL)
		postorder(n->left);
	if(n->right!=NULL)
		postorder(n->right);
	printf("%d\t",n->value);
}
int height(node *n)
{
	if(n==NULL)
		return 0;
	else
	{
		int lh=height(n->left);
		int rh=height(n->right);
		if(lh>rh)
			return (lh+1);
		else if(rh>lh)
			return (rh+1);
		else if(lh==rh)
			return (lh+1);
	}
}
void main()
{
	int choice,n;
	printf("Operations:\n");
	printf("1.Insert a node in the tree:\n");
	printf("2.Delete a node from the tree:\n");
	printf("3.Search a node in the tree:\n");
	printf("4.Traversal:\n");
	printf("5.Height of the tree:\n");
	while(1)
	{
		printf("enter a choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				printf("enter a node you want to search:\n");
				scanf("%d",&n);
				search(n,root);
				break;
			case 4:
				printf("Preorder Traversal:\n");
				preorder(root);
				printf("\n");
				printf("Inorder Traversal:\n");
				inorder(root);
				printf("\n");
				printf("Postorder Traversal:\n");
				postorder(root);
				printf("\n");
				break;
			case 5:
				printf("Height of the tree is: %d",height(root));
				printf("\n");
				break;
			case 6:
				exit(0);
			default:
				printf("wrong choice\n");
		}
	}
}
