#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left,*right;
    int info,rthread;
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
NODE *Insertright(NODE *p,int n)
{
	NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->info=n;
    nn->left=NULL;
    nn->right=p->right;
    p->right=nn;
    nn->rthread=1;
    p->rthread=0;
    return nn;
}
NODE *Insertleft(NODE *p,int n)
{
	NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->info=n;
    nn->left=NULL;
    nn->right=p;
    p->left=nn;
    nn->rthread=1;
    p->rthread=0;
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
			p->right=Insertright(p,n);
		else
			p->left=Insertleft(p,n);
		printf("do you want to continue?\n");
		scanf("%d",&z);
	}
	return root;
}




void traverse(NODE *root)
{
	if(root!=NULL)
	{
		traverse(root->left);
		printf("%d\t",root->info);
		traverse(root->right);
	}
    
}


void main()
{
	
	NODE *root=NULL;
	root=createtree(root);
	traverse(root);

}