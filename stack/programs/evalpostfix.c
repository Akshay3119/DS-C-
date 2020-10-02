#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct stack{
int info[MAX];
int top;
};
typedef struct stack STACK;

void push(STACK  *s,int n)
{

    if(s->top==MAX-1)
    {
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->info[s->top]=n;
}
int pop(STACK *s)
{
   int n;
   if(s->top==-1)
   {
        printf("Underflow\n");
        return;
   }
   n=s->info[s->top];
   s->top--;
   return n;
}



void main()
{
    int i,n,x,op1,op2,result;
    char PE[10],ch;
    printf("Enter postfix expression: ");
    scanf("%s",PE);
    STACK s;
    s.top=-1;
    for(i=0;PE[i]!='\0';i++)
    {
        ch=PE[i];
        if(ch>='0' &&  ch<='9')
            push(&s,(ch-48));
        else
        {
            op2=pop(&s);
            op1=pop(&s);
        switch(ch)
        {
            case '*': {result=op1*op2;
                              break;}
            case '/': {result=op1/op2;
                              break;}
            case '+': {result=op1+op2;
                              break;}
            case '-': {result=op1-op2;
                              break;}
        }
       push(&s,result);
   }
    }
    printf("%d",s.info[s.top]);

}
