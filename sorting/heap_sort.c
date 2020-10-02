#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void getdata(int *A,int n)
{
	for(int i=0;i<n;i++)
		scanf("%d",A+i);
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

void sort(int *A,int n)
{
    while(n>0)
    {
        swap((A+0),(A+n-1));
        n=n-1;
        heapify(A,0,n);
    }
}


void main()
{
	int n,A[MAX];
	printf("enter no of elements\t");
	scanf("%d",&n);
	getdata(A,n);
	for(int i=n/2;i>=0;i--)
		heapify(A,i,n);
	sort(A,n);
	display(A,n);
}