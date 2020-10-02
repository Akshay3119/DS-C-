#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node{
    struct node *left;
    struct node *right;
    int info;
};
typedef struct node NODE;

NODE *createnode(int n)
{
  NODE *nn;
  nn=(NODE*)malloc(sizeof(NODE));
  nn->left=nn->right=NULL;
  nn->info=n;
  return nn;  
}


NODE *createtree(NODE *root)
{
	NODE *p,*c;
	int z=1,n,x;
	printf("enter info part of root\n");
	scanf("%d",&x);
	root=createnode(x);
	while(z!=0)
	{
		printf("enter info part of next node\n");
		scanf("%d",&n);
		p=c=root;
		while(c!=NULL)
		{
			p=c;
			if(n>p->info)
				c=p->right;
			else
				c=p->left;

		}
		if(n>p->info)
			p->right=createnode(n);
		else
			p->left=createnode(n);
		printf("do you want to continue?\n");
		scanf("%d",&z);
	}
	return root;
}




void find(NODE *root,int x,int *y)
{
	
	
	if(root!=NULL)
	{
		find(root->left,x,y);
		if(root->info==x)
		{
			*y=1;	
		}
		if(*y==1)
			printf("%d\t",root->info);
		find(root->right,x,y);
	}
	
}


void main()
{
	int x,y=0;
	
	NODE *root=NULL;
	root=createtree(root);

    printf("\nenter value to be searched\n ");
	scanf("%d",&x);
	printf("\nSearching...");
	find(root,x,&y);
	if(y==0)
		printf("value not found");
	

}