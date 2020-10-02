

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

struct opndstack
{
int top;
double items[MAX];
};

struct optrstack
{
int top;
char items[MAX];
};

void pushopnd(struct opndstack *s,double val)
{
if(s->top==MAX-1)
{
printf("nStack Overflow.");
exit(1);
}
else
{s->items[++(s->top)]=val;
}
}

double popopnd(struct opndstack *s)
{
if(s->top==-1)
{
printf("\nStack Underflow");
exit(1);
}
else
{
return(s->items[(s->top)–]);
}
}

void pushoptr(struct optrstack *s,char ch)
{
if(s->top==MAX-1)
{
printf("nStack Overflow.");
exit(1);
}
else
{s->items[++(s->top)]=ch;
}
}

char popoptr(struct optrstack *s)
{
if(s->top==-1)
{
printf("\nnStack Underflow.");
exit(1);
}
else
{
return(s->items[(s->top)–]);
}
}

int isdigit(char ch)
{return(ch>='0′ && ch<='9′);
}

int isoperator(char ch)
{
switch(ch)
{
case '+':
case '-':
case '*':
case '/':
case '^':
return 1;
default:
return 0;
}
}



double eval(char ch,double opnd1,double opnd2)
{
switch(ch)
{
case '+':return(opnd1+opnd2);
case '-':return(opnd1-opnd2);
case '*':return(opnd1*opnd2);
case '/':return(opnd1/opnd2);
case '^':return(pow(opnd1,opnd2));
default:printf("nInvalid operator.");
exit(1);
}
}

int precedence(char ch)
{
switch(ch)
{
case '#': return 0;
case '+':
case '-': return 1;
case '*':
case '/':return 2;
case '^':return 3;
case '(':return 4;
default :printf("nInvalid operator.");

}
}



double infix(char str[])
{
double opnd1,opnd2,value;
char ch;
opndstack opndstk;
optrstack optrstk;
opndstk.top=-1;
optrstk.top=-1;
pushoptr(&optrstk,'#');
int i=0;
char optr2;
for(i=0;str[i]!='\0';i++)
{
if(isdigit(str[i]))
pushopnd(&opndstk,(double)(str[i]-'0′));
else if(isoperator(str[i]))
{optr2=popoptr(&optrstk);
if(precedence(str[i])>precedence(optr2))
{pushoptr(&optrstk,optr2);
pushoptr(&optrstk,str[i]);
}
else
{
while(precedence(str[i])<=precedence(optr2))
{ opnd2=popopnd(&opndstk);
opnd1=popopnd(&opndstk);
value = eval(optr2,opnd1,opnd2);
pushopnd(&opndstk,value);
optr2=popoptr(&optrstk);
}
pushoptr(&optrstk,optr2);
pushoptr(&optrstk,str[i]);
}
}
}
while((ch=popoptr(&optrstk))!='#')
{
opnd2=popopnd(&opndstk);
opnd1=popopnd(&opndstk);
value=eval(ch,opnd1,opnd2);
pushopnd(&opndstk,value);
}
return(popopnd(&opndstk));
}

void main()
{
char str[80];
int i;
clrscr();
printf("nEnter an infix string?");
gets(str);
printf("nInfix String = %s",str);
printf("nEvaluation of infix = %f",infix(str));
getch();
}
