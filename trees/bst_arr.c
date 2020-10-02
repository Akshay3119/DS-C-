#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void create(int *A)
{
	int n,z=1,ipr,ich;
    printf("enter root info");
	scanf("%d",A+0);
	ipr=0;
	do
	{
		ipr=0;
		printf("enter info part of nn ");
		scanf("%d",&n);
		while(*(A+ich)!=0)
		{	
		    if(n>*(A+ipr))
		      ich=2*ipr+2;
		    else
		      ich=2*ipr+1;
		    ipr=ich;
	    }
		
		*(A+ich)=n;

		printf("do you want to addmore nodes? ");
		scanf("%d",&z);
		}while(z!=0);
}
void display(int *A)
{
	for(int i=0;i<7;i++)
	  printf("%d\t",*(A+i));
}
void main()
{
	int A[MAX];
	for(int i=0;i<7;i++)
	  A[i]=0;
	create(A);
	display(A);	
}