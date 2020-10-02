#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    char PE1[10],PE[10],ch;
    printf("Enter prefix expression: ");
    int len,j=0;
  
    scanf("%s",PE1);
    len=strlen(PE1);
    for( i=len-1;i>=0;i--)
      PE[j++]=PE1[i];
    PE[len]='\0';
    STACK s;
    s.top=-1;
    for(i=0;PE[i]!='\0';i++)
    {
        ch=PE[i];
        if(ch>='0' &&  ch<='9')
            push(&s,(ch-48));
        else
        {
            op1=pop(&s);
            op2=pop(&s);
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
