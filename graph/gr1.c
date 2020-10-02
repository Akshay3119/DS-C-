#include<stdio.h>
#include<stdlib.h>
void multi(int **a,int **b,int n)
{
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				*(*(b+i)+j)= *(*(b+i)+k) * *(*(a+k)+j);
}		
	
void addition(int **a,int **b, int n)
{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				*(*(b+i)+j) += *(*(a+i)+j);
}

void display(int **X,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		    printf("%d  ",*(*(X+i)+j));
		printf("\n");
	}

}

void main()
{
	int n,z;
	int **a,**b,**c;
	printf("Enter n\t");
	scanf("%d",&n);
	a=(int**)malloc(n*sizeof(int*));
	b=(int**)malloc(n*sizeof(int*));
	c=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++)
	{
		*(a+i)=(int*)malloc(n*sizeof(int));
		*(b+i)=(int*)malloc(n*sizeof(int));
		*(c+i)=(int*)malloc(n*sizeof(int));
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			printf("Is there a path from %c to %c ",65+i,65+j);
			scanf("%d",&z);
			*(*(a+i)+j)=z;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			*(*(b+i)+j)=*(*(a+i)+j);
			*(*(c+i)+j)=*(*(a+i)+j);
		}
	printf("\n");
	display(a,n);
	printf("\n");
	multi(a,b,n);
	display(b,n);
	printf("\n");
	
	for(int i=0;i<n-2;i++)
	{
		addition(b,c,n);
		multi(a,b,n);
		display(b,n);
		printf("\n");
		display(c,n);
		printf("\n");
	}
	addition(b,c,n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(*(*(c+i)+j)>0)
				*(*(c+i)+j)=1;
			else
				*(*(c+i)+j)=0;
		}
	printf("\n");
	display(c,n);
}
