#include<stdio.h>
void multi(int a[][30],int b[][30],int n)
{
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				b[i][j]=b[i][k]*a[k][j];
}		
	
void addition(int a[][30],int b[][30], int n)
{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				b[i][j]+=a[i][j];
}

void display(int X[][30],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		    printf("%d  ",X[i][j]);
		printf("\n");
	}

}

void main()
{
	int n,z;
	int a[30][30],b[30][30],c[30][30];
	printf("Enter n\t");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			printf("Is there a path from %c to %c ",65+i,65+j);
			scanf("%d",&z);
			a[i][j]=z;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
				c[i][j]=a[i][j];
				b[i][j]=a[i][j];
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
			if(c[i][j]>0)
				c[i][j]=1;
			else
				c[i][j]=0;
		}
	printf("\n");
	display(c,n);

}
