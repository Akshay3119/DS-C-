#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct stack{
int info[MAX];
int top;
};
typedef struct stack STACK;

void push(STACK  *s,char n)
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

int PRECD(char sym)
{
    switch(sym){
  case'*':
  case'/':{
    return 2;
    break;
  }
  case'+':
  case'-':{
    return 1;
    break;
  }
  case'(':{
    return 0;
    break;
  }
    }
}

void display(STACK *POST)
{
  for (int i=0;i<=POST->top;i++)
    printf("%c",POST->info[i]);
}


STACK *Infixtopostfix(char ch[],STACK *s,STACK *POST)
{
  int i,pre1,pre2;
  char sym,op;
  for(i=0;ch[i]!='\0';i++)
  {
    sym=ch[i];
    if(sym>='0' &&  sym<='9')
      push(POST,sym);
    else if(sym=='+'||sym=='-'||sym=='*'||sym=='/')
    {
      if(s->top==-1)
      {
        push(s,sym);
        continue;
      }
      pre1=PRECD(sym);
      pre2=PRECD(s->info[s->top]);
      if(pre1>pre2)
      {
        push(s,sym);
        
      }
      if(pre1<=pre2)
      {
        op=pop(s);
        
        push(POST,op);
        
        push(s,sym);
        
      }

    }
    else if(sym=='(')
      push(s,sym);
    else if(sym==')')
    {
      op=pop(s);
      while(op!='(')
      {
        push(POST,op);
        op=pop(s);
      } 
    }

  }
  if(s->top!=-1&&ch[i]=='\0')
  {
    while(s->top!=-1)
    {
      op=pop(s);
      push(POST,op);
    }
  }
}

void main()
{
  STACK s,POST;
  char IE[10];
  printf("Enter infix expression: ");
    scanf("%s",IE);
    
    s.top=-1;
    POST.top=-1;
    Infixtopostfix(IE,&s,&POST);
    printf("postfix expression:\n");
    display(&POST);
}