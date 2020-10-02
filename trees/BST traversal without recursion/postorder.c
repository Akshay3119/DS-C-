#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node{
    struct node *left;
    struct node *right;
    int info;
};
typedef struct node NODE;

struct stack{
	NODE *info[MAX];
	int top;
};


typedef struct stack STACK;


void push(STACK *s,NODE *n)
{

    if(s->top==MAX-1)
    {
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->info[s->top]=n;
}


NODE *pop(STACK *s)
{
   NODE *n;
   if(s->top==-1)
   {
        printf("Underflow\n");
        return;
   }
   n=s->info[s->top];
   s->top--;
   return n;
}


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
	printf("enter info part of root\t");
	scanf("%d",&x);
	root=createnode(x);
	while(z!=0)
	{
		printf("enter info part of next node\t");
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
		printf("do you want to continue?\t");
		scanf("%d",&z);
	}
	return root;
}


void traverse(STACK *s1,STACK *s2,NODE *root)
{
	NODE *p,*q;
	push(s1,root);
	while(s1->top!=-1)
	{
		q=pop(s1);
		push(s2,q);
		if(q->left!=NULL)
			push(s1,q->left);
		if(q->right!=NULL)
			push(s1,q->right);
	}
	while(s2->top!=-1)
	{
		p=pop(s2);
		printf("%d\t",p->info);
	}
}


void main()
{
	STACK s1,s2;
    NODE *root=NULL;
    s1.top=s2.top=-1;
	root=createtree(root);
	traverse(&s1,&s2,root);
}