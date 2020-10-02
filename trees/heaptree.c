#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void create(int *A,int n)
{
	int k,ipr,ich;
    printf("enter root info ");
	scanf("%d",A+0);
	ipr=0;
	for(int i=0;i<n-1;i++)
	{
		ipr=0;
		printf("enter info part of nn ");
		scanf("%d",&k);
		while(*(A+ich)!=0)
		{	
		    if(k>*(A+ipr))
		      ich=2*ipr+2;
		    else
		      ich=2*ipr+1;
		    ipr=ich;
	    }
		
		*(A+ich)=k;
	}
}

void swap(int *a,int *b)
{
	int c;
	c=*b;
	*b=*a;
	*a=c;
}

void heapify(int *A,int i, int n)
{
	int lc,rc,l;
	lc=2*i+1;
	rc=2*i+2;
	l=i;
	if(lc<n && *(A+lc)>*(A+i))
		l=lc;
	if(rc<n && *(A+rc)>*(A+l))
		l=rc;
	if(l!=i)
	{
		swap((A+i),(A+l));
		heapify(A,l,n);
	}

}

void display(int *A,int n)
{
	for(int i=0;i<n;i++)
	  printf("%d\t",*(A+i));
}


void main()
{
	int n,A[MAX];
	printf("enter no of elements\t");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  A[i]=0;
	create(A,n);
	printf("\ntree created\n");
	for(int i=n/2;i>=0;i--)
		heapify(A,i,n);
	display(A,n);
}