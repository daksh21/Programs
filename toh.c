// Program to implememt tower of honoi problem
// Author: Daksh Agarwal

#include<stdio.h>
#include<math.h>
#include<string.h>
char a1[50],a2[50],a3[50];
int top1=0,top2=0,top3=0;
string[] b={a1,a2,a3};
void main()
{
	int n,i,s,a,b;
	printf("\nenter the number of disks:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		pusha1(n-i);
	}
	s=pow(2,n)-1;
	for(i=1;i<=s;i++){
		if(i%3==1){
			a=popa1();
			b=popa3();
			if(a==0)
				pusha1(b);
			else if(b==0)
				pusha3(a);
			else if(a>b){
				pusha1(a);
				pusha1(b);
			}
			else{
				pusha3(b);
				pusha3(a);
			}
			show();
			continue;
		}
		else if(i%3==2){
			a=popa1();
			b=popa2();
			if(a==0)
				pusha1(b);
			else if(b==0)
				pusha2(a);
			else if(a>b){
				pusha1(a);
				pusha1(b);
			}
			else{
				pusha2(b);
				pusha2(a);
			}
			show();
			continue;
		}
		else if(i%3==0){
			a=popa2();
			b=popa3();
			if(a==0)
				pusha2(b);
			else if(b==0)
				pusha3(a);
			else if(a>b){
				pusha2(a);
				pusha2(b);
			}
			else{
				pusha3(b);
				pusha3(a);
			}
			show();
			continue;
		}
	}
}
void pusha1(int a){
	if(a!=0){
		a1[top1++]=a;
	}
}
int popa1(){
	if(top1==0){
		return 0;
	}
	else{
		int p;
		p=a1[--top1];
		return p;
	}
}
void showa1(){
	int i;
	printf("\npeg1:");
	if(top1==0)
		printf("Empty");
	else{
		for(i=0;i<top1;i++)
			printf("%d",a1[i]);
	}
	printf("\t");
}
void pusha2(int a){       
	if(a!=0)
	{
		a2[top2++]=a;
	}
}       
int popa2(){       
	if(top2==0){
		return 0;
	}
	else{
		int p;
		p=a2[--top2];
		return p;
	}
}       
void showa2(){       
	int i;
	printf("peg2:");
	if(top2==0)
		printf("Empty");
	else{
		for(i=0;i<top2;i++)
			printf("%d",a2[i]);
	}
	printf("\t");
}
void pusha3(int a){       
	if(a!=0){
		a3[top3++]=a;
	}
}       
int popa3(){       
	if(top3==0){
		return 0;
	}
	else{
		int p;
		p=a3[--top3];
		return p;
	}
}       
void showa3(){       
	int i;
	printf("peg3:");
	if(top3==0)
		printf("Empty");
	else{
		for(i=0;i<top3;i++)
			printf("%d",a3[i]);
	}
	printf("\t");
}
void show(){
	string msg=" ";
	int MaxLength = 0,i;
	MaxLength=max(strlen(a1,a2,a3));
	for(i=0;i<MaxLength;i++){
		for(j=0;j<2;j++)
			printf("%d",);

	}
	for(i=0;i<b.Length;i++){
		if(b[i].Length>MaxLength) MaxLength=b[i].Length;
	}       
	for(i=0;i<b.Length;i++){       
		while(b[i].Length<MaxLength){       
			b[i]+=" ";
		}       
	}
