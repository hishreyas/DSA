/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
a) A postfix expression of the formab+cd-*ab/ is to be evaluated after accepting the values of 
a, b, c and d. The value should be accepted only once and the same value is to be used for 
repeated occurrence of same symbol in the expression. Formulate the problem and write a C 
program to solve the problem by using stack
*/

#include<stdio.h>
#include<stdlib.h>
#include "cststack.h"
#include "dystack.h"

int evaluate(char *str,int a,int b,int c,int d)
{
  Stack *stack=newStack();
  int i,sum=0,operand1,operand2;
  
  for(i=0;str[i]!='\0';i++)
  {
    if(isOperand(str[i]))
    {
      if(str[i]=='A'||str[i]=='a')
       push(stack,a);
      if(str[i]=='B'||str[i]=='b')
        push(stack,b);
      if(str[i]=='C'||str[i]=='c')
        push(stack,c);
      if(str[i]=='D'||str[i]=='d')
        push(stack,d);
    }
    if(isOperator(str[i]))
    {
      operand2=pop(stack);
      operand1=pop(stack);
      
      if(str[i]=='+')
      push(stack,operand1+operand2);
      if(str[i]=='-')
      push(stack,operand1-operand2);
      if(str[i]=='*')
      push(stack,operand1*operand2);
      if(str[i]=='/')
      push(stack,operand1/operand2);
    }
  }
  sum=pop(stack);
  free(stack);
  return sum;
}

int main()
{
  char str[25];
  int a,b,c,d;
  
  puts("Enter postfix string:");
  gets(str);
  
  puts("Enter value for a b c d");
  scanf("%d%d%d%d",&a,&b,&c,&d);
  
  printf("%s=%d\n",str,evaluate(str,a,b,c,d));
  
  return 0;
}