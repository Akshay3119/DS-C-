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




int find(NODE *root,int x)
{
	int y=0;
	
	if(root!=NULL)
	{
		find(root->left,x);
		if(root->info==x)
		{
			y=1;
			
		}
		find(root->right,x);
	}
	return y;
}


void main()
{
	int x;
	
	NODE *root=NULL;
	root=createtree(root);
printf("\nSearching...");
printf("\nenter value to be searched\n ");
	scanf("%d",&x);
	int z=find(root,x);
	if(z==1)
	{
		printf("found");
	}
	else
		printf("not found");

}