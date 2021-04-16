/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A,
b)Write a program to convert an infix expressionof the form (a*(b+c)*((d-a)/b)) intoits 
equivalent postfix notation. Consider usual precedence’s of operators. Use stack library of 
stack of characters using static implementation.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cststack.h"


int main()
{
  char infix[25],output[40];
  
  puts("Enter infix:");
  gets(infix);
  
  puts("Postfix :");
  infixToPostfix(output,infix);
  puts(output);
  
  return 0;
}