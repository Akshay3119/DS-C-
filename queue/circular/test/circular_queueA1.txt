#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct Queue{
int info[MAX];
int rear,front;
};
typedef struct Queue QUEUE;

void enqueue(QUEUE *q,int n)
{
  if((q->front==0 && q->rear==MAX-1)||(q->rear==q->front-1))
     {printf("Queue is full\n");
     return;}
  if(q->front=-1)
     q->front=q->rear=0;
  else if(q->rear=MAX-1)
     q->rear=0;
  else
     q->rear++;
  q->info[q->rear]=n;
}

int dequeue(QUEUE *q)
{ int n;
  if (q->front==-1 && q->rear==-1)
     {printf("Queue is empty\n");
      return;}
  n=q->info[q->front];
  if (q->front==q->rear)
     q->front=q->rear-1;
  else if(q->front=MAX-1)
     q->front=0;
  else
     q->front++;
  return n;
}

void display(QUEUE *q)
{

}

void main()
{
  int n,z,x;
  QUEUE q;
  q.rear=q.front=-1;
  do{
    printf("\n1.Enqueue\n 2.Dequeue\n 3.exit\n");
    scanf("%d",&z);
    switch(z)
    {
      case 1:{printf("enter element to be added in queue\n");
              scanf("%d",&n);
              enqueue(&q,n);
              break;}
      case 2:{x=dequeue(&q);
              printf("Deleted Element:%d",x);
              break;}
      case 3: break;

    }
  }while(z!=3);
  display(&q);
}
