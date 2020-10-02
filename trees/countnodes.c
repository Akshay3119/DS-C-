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




int cnode(NODE *root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL&&root->right==NULL)
		return 1;
	else
		return 1+cnode(root->left)+cnode(root->right);
}


void main()
{
	
	NODE *root=NULL;
	root=createtree(root);
	int n=cnode(root);
	printf("\nNo of nodes in the tree are %d",n);

}