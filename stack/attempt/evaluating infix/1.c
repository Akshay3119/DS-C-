#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
struct stack{
int info[MAX];
int top;
};
struct stack1{
char info[MAX];
int top;
};
typedef struct stack STACK;
typedef struct stack1 STACK1;

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
void push1(STACK1  *s,char n)
{

    if(s->top==MAX-1)
    {
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->info[s->top]=n;
}
char pop1(STACK1 *s)
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

int eval(int op1,char ch,int op2)
{
switch(ch)
{
case '+':return(op1+op2);
case '-':return(op1-op2);
case '*':return(op1*op2);
case '/':return(op1/op2);
default:printf("\nInvalid operator.");
}
}


int prec(STACK1 *s,char ch)
{
switch(s->top)
{
  case'*':
  case'/':{if (ch=='(')
           return 0;
           else
           return 1;
           break;}
  case'+':
  case'-':{if (ch=='+'||ch=='-')
            return 1;
             else
             return 0;
             break;}
  case '(':{return 0;
           break;}
}
}



void main()
{
    int k,i,n,op1,op2,res,value;
    char IE[10],ch,optr,sym,ch1;
    printf("Enter infix expression: ");
    scanf("%s",IE);
    STACK *s;
    STACK1 *s1;
    s=(STACK*)malloc(sizeof(STACK));
    s1=(STACK*)malloc(sizeof(STACK));
    s->top=-1;
    s1->top=-1;
    
    for(i=0;IE[i]!='\0';i++)
    {
        ch=IE[i];
        if(ch>='0' && ch<='9')
            push(&s,(ch-48));
        else
            {
                optr=ch;

                if(s1->top==-1)
                { 
                  push1(&s1,optr);
                }
                else
                {
                  if(prec(&s1,optr))
                  {
                    sym=pop1(&s1);
                    op2=pop(&s);
                    op1=pop(&s);
                    k=eval(op1,sym,op2);
                    push(&s,k);
                  }
                  
                  else
                  push1(&s1,optr);
                }
          }
  }
  if(s->top!=-1&&IE[i]=='\0')
  {
    while(s->top!=-1)
    {
      op2=pop(&s);
      op1=pop(&s);
      ch1=pop1(&s1);
      value=eval(op1,ch1,op2);
      push(&s,value);
    }
  }


printf("%d",s->info[s->top]);
}
