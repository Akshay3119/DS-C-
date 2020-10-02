#include <stdio.h>
#define MAX 5
 
//Declaration of priority queue
typedef struct
{
    int ele[MAX][MAX];
    int count;
}PQueue;
 
//Initialize priority queue
void init(PQueue *q)
{
    int i=0;
    q->count = 0;
      
    //All priority value set to -1
    for( i = 0; i < MAX ; i++ )
    {
        q->ele[i][1] = -1 ;  
    }
}
 
//Insert item with priority in queue
void insertWithPriority(PQueue *q, int priority, int item )
{
    int i = 0;
    if( q->count == MAX )
    {
        printf("\nPriority Queue is overflow");
        return;
    }
 
    for ( i = 0; i < MAX; i++ )
    {
        if( q->ele[i][1] == -1)
            break;
    }
     
    q->ele[i][0] = item;
    q->ele[i][1] = priority;
 
    q->count++;
    printf("\nInserted item is : %d",item);
}
 
//Remove & get element with highest priority in queue
int GetNext(PQueue *q, int *item)
{
    int i = 0,max,pos=0;
 
    if( q->count == 0 )
    {
        printf("\nPriority Queue is underflow");
        return -1;
    }
     
    max = q->ele[0][1];
    for ( i = 1; i < MAX; i++ )
    {
        if( max < q->ele[i][1] )
        {
            pos = i;
            max = q->ele[i][1];
        }
    }
     
    *item = q->ele[pos][0];  
    q->ele[pos][1] = -1;
 
    q->count--;
    return 0;   
}
 
//Get element with highest priority without removing it from queue
int PeekAtNext(PQueue *q, int *item)
{
    int i = 0,max,pos=0;
 
    if( q->count == 0 )
    {
        printf("\nPriority Queue is underflow");
        return -1;
    }
     
    max = q->ele[0][1];
    for ( i = 1; i < MAX; i++ )
    {
        if( max < q->ele[i][1] )
        {
            pos = i;
            max = q->ele[i][1];
        }
    }
     
    *item = q->ele[pos][0];  
 
    return 0;   
}
 
 
int main()
{
    int item;
    PQueue q;
     
    init( &q );
 
    insertWithPriority( &q, 1, 10 );
    insertWithPriority( &q, 2, 20 );
    insertWithPriority( &q, 3, 30 );
    insertWithPriority( &q, 4, 40 );
    insertWithPriority( &q, 5, 50 );
    insertWithPriority( &q, 6, 60 );
 
    if( PeekAtNext( &q, &item) == 0 )
        printf("\nPeek Item : %d",item);
 
 
    if( GetNext( &q, &item) == 0 )
        printf("\nItem : %d",item);
     
    if( PeekAtNext( &q, &item) == 0 )
        printf("\nPeek Item : %d",item);
 
    if( GetNext( &q, &item) == 0 )
        printf("\nItem : %d",item);
    if( GetNext( &q, &item) == 0 )
        printf("\nItem : %d",item);
 
     
    if( PeekAtNext( &q, &item) == 0 )
        printf("\nPeek Item : %d",item);
 
    if( GetNext( &q, &item) == 0 )
        printf("\nItem : %d",item);
    if( GetNext( &q, &item) == 0 )
        printf("\nItem : %d",item);
    if( GetNext( &q, &item) == 0 )
        printf("\nItem : %d",item); 
 
 
    printf("\n");
     
    return 0;
}