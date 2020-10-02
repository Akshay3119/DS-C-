#include<stdio.h>
#include<stdlib.h>
#define MAX 6
struct Node{
	int info,pr;
	struct Node *next;
};
typedef struct Node NODE;
NODE *Enqueue(NODE *last,int *c)
{
	if(*c<=0)
		{
		    printf("queue is empty\n");
		    return;
	    }
	    NODE *nn,*temp;
		nn=(NODE*)malloc(sizeof(NODE));
		printf("enter first element\n");
		scanf("%d",&nn->info);
		printf("enter its priority\n");
		scanf("%d",&nn->pr);
		
		if(last==NULL)
		{
			nn->next=nn;
			last=nn;
			return last;
		}
		else
			{
				temp=last->next;
				last->next=nn;
	            nn->next=temp;
	            last=nn;
	            *c=*c+1;
	            return last;
			}
		
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
	do
	{
		if(p>start->pr)
			p=start->pr;
		start=start->next;
	}while(start!=last);
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
	NODE *last=NULL;
	int z,c=1;
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
