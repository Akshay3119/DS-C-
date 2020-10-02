#include<stdio.h>
#include<stdlib.h>

void mergeS(int X[],int n)
{
	int size=1,l1,l2,u1,u2,i,j,k;
	int temp[20];
	while(size<n)
	{
		l1=k=0;
		while((l1+size)<n)
		{
			l2=l1+size;
			u1=l2-1;
			u2=(l2+size-1)<n?l2+size-1:n-1;
			for(i=l1, j=l2 ; i<=u1&&j<=u2 ; k++)
			{
				if(*(X+i)<*(X+j))
					*(temp+k)=*(X+i++);
				else
					*(temp+k)=*(X+j++);
			}
			while(i<=u1)
				*(temp+k++)=*(X+i++);
			while(j<=u2)
				*(temp+k++)=*(X+j++);
			l1=u2+1;
		}
		for(i=l1;k<n;k++)
			*(temp+k)=*(X+i++);
		for(i=0;i<n;i++)
			*(X+i)=*(temp+i);
		size=size*2;
	}
	for(i=0;i<n;i++)
		printf("%d  ",*(temp+i));
}
void main()
{
	int n,X[20];
	printf("enter size of array \t");
	scanf("%d ",&n);
	for(int i=0;i<n;i++)
		scanf("%d ",X+i);
	mergeS(X,n);
}