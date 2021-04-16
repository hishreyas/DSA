/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
b) Write a program that copies the contents of one stack into another. Use stack library to 
perform basic stack operations. The order of two stacks must be identical.(Hint: Use a 
temporary stack to preserve the order).
*/

#include<stdio.h>
#include<stdlib.h>
#include "dystack.h"

int main()
{
  Stack *s1,*s2;
  
  s1=newStack();
  s2=range(2,20,2);
  
  printf("\nBefore copying stack 2 into stack 1\n");

  printf("\nStack 2:");
  display(s2);
  printf("\nStack 1:");
  display(s1);
 
  stackCpy(s1,s2);
  printf("\nAfter copying :stack 2 into stack 1\n");
  
  printf("\nStack 2:");
  display(s2);
  printf("\nStack 1:");
  display(s1);

  return 0;
}