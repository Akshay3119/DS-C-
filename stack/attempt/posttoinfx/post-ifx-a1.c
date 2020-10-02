#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct stack{
char info[MAX][MAX];
int top;
char *ptr;
};
typedef struct stack STACK;

void push(STACK  *s,char n[])
{

    if(s->top==MAX-1)
    {
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->info[s->top]=n[];
}

char *pop(STACK *s)
{
   int n[];
   if(s->top==-1)
   {
        printf("Underflow\n");
        return;
   }
   n=s->info[s->top];
   s->top--;
   return n[];
}



 postfixtoifx()
{
    int i,n,x,result;
    char PE[10],ch,op1[15],op2[15],str[15],str1[15],str2,str3[15];
    printf("Enter postfix expression: ");
    scanf("%s",PE);
    STACK s;
    s.top=-1;
    for(i=0;PE[i]!='\0';i++)
    {
        ch=PE[i];
        if(ch>='0' &&  ch<='9')
            push(&s,ch);
        else
        {
            op2[]=pop(&s);
            op1[]=pop(&s);
            str[]={'(',op1,ch,op2,')'};
            push(&s,str);
        }

    }
    printf("%s",s.info[s.top]);

}

void main()
{
    int **a;
    a=(int**)malloc(MAX*sizeof(int *));
    for(int i=0;i<MAX;i++)
        *(a+i)=(int*)malloc(MAX*sizeof(int));

}
