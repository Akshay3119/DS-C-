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


void traverse(STACK *s,NODE *root)
{
	NODE *p;
	p=root;
	do{
		while(p!=NULL)
		{
			push(s,p);
			p=p->left;
		}
		p=pop(s);
		printf("%d\n",p->info);
		p=p->right;
	}while(s->top!=-1||p!=NULL);
}


void main()
{
	STACK s;
    NODE *root=NULL;
    s.top=-1;
	root=createtree(root);
	traverse(&s,root);
}