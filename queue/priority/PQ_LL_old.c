#include<stdio.h>
#include<stdlib.h>
#define MAX 6
struct Node{
	int info,pr;
	struct Node *next;
};
typedef struct Node NODE;
NODE *create(NODE *start)
{
	    NODE *nn,*pn;
		nn=(NODE*)malloc(sizeof(NODE));
		printf("enter first element\n");
		scanf("%d",&nn->info);
		printf("enter its priority\n");
		scanf("%d",&nn->pr);

		nn->next=NULL;
		if(start==NULL)
			start=nn;
		else
			pn->next=nn;
		nn->next=start;
		pn=nn;
	    return nn;
}
void display(NODE *last,int *c)
{
	if(*c<=0)
		{
		    printf("queue is empty\n");
		    return;
	    }
	NODE *start;
	start=last->next;
	do{
		printf("Element: %d\tPriority: %d\n",start->info,start->pr);
		start=start->next;
	}while(start!=last->next);
}
NODE *Enqueue(NODE *last,int *c)
{
	if(*c>=MAX-1)
	{
		printf("queue is full\n");
		return;
	}
	
	NODE *start,*nn;
	nn=(NODE*)malloc(sizeof(NODE));
	printf("enter info part\n");
	scanf("%d",&nn->info);
	printf("enter its priority\n");
    scanf("%d",&nn->pr);
	start=last->next;
	last->next=nn;
	nn->next=start;
	last=nn;
	*c=*c+1;
	return last;
    
}
void Dequeue(NODE *last,int *c)
{
	int p=99;
	if(*c<=0)
		{
		printf("queue is empty\n");
		return;
	    }
	
	NODE *pn,*start;
	start=last->next;
	while(start!=last)
	{
		if(p>start->pr)
			p=start->pr;
		start=start->next;
	}
	do
	{
		if(start->pr==p)
		{
			pn->next=start->next;
			printf("deleted element is %d\n",start->info);
			free(start);
			*c=*c-1;
			return;
		}
		pn=start;
		start=start->next;
	}while(start!=last);
}


void main()
{
	NODE *last,*start=NULL;
	int z,c=1;
	last=create(start);
	  do{
    printf("\n 1.Enqueue\n 2.Dequeue\n 3.display\n 4.exit\n ");
    scanf("%d",&z);
    switch(z)
    {
      case 1:{last=Enqueue(last,&c);
              break;}
      case 2:{Dequeue(last,&c);
              break;}
      
      case 3:{display(last,&c);
              break;}
      case 4: break;
    }
  }while(z!=4);
  display(last,&c);
}
