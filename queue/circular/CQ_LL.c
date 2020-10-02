#include<stdio.h>
#include<stdlib.h>
#define MAX 6
struct Node{
	int info;
	struct Node *next;
};
typedef struct Node NODE;
NODE *create(NODE *start)
{
	    NODE *nn,*pn;
		nn=(NODE*)malloc(sizeof(NODE));
		printf("enter first element\n");
		scanf("%d",&nn->info);
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
		printf("%d\t",start->info);
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
	start=last->next;
	last->next=nn;
	nn->next=start;
	last=nn;
	*c=*c+1;
	printf("value of c is %d\n",*c);
	return last;
    
}
void Dequeue(NODE *last,int *c)
{
	if(*c<=0)
		{
		printf("queue is empty\n");
		return;
	    }
	
	NODE *temp,*start;
	start=last->next;
	temp=start->next;
	printf("deleted element is %d\n",start->info);
	free(start);
	last->next=temp;
	*c=*c-1;
    printf("value of c is %d\n",*c);
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
