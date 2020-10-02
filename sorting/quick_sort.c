#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int c;
	c=*b;
	*b=*a;
	*a=c;
}

void quick_sort(int *A,int lb,int ub)
{
	if(ub>lb)
	{
	int up=ub;
	int down=lb;
	int pivot=*(A+lb);
	while(down<up)
	{
		while(*(A+down)<=pivot && down<ub)
			down++;
		while(*(A+up)>pivot && lb<=up)
			up--;
		if(down<up)
			swap((A+down),(A+up));
	}
	swap((A+lb),(A+up));  //swapping pivot and up
	quick_sort(A,lb,up-1);
	quick_sort(A,up+1,ub);
    }

}

void display(int A[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d  ",A[i]);
}

void main()
{
	int n,A[15],lb,ub;
	printf("enter size of array: ");
	scanf("%d",&n);
	lb=0;
	ub=n-1;
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	quick_sort(A,lb,ub);
	display(A,n);

}
