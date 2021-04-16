/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
a) Write a program to check whether the contents of two stacks are identical. Use stack 
library to perform basic stack operations. Neither stack should be changed.
*/

#include<stdio.h>
#include<stdlib.h>
#include "dystack.h"

int main()
{
  Stack *s1,*s2;
  
  s1=range(2,20,2); //2 4 6 ..20
  s2=range(1,10,1); //1..10
  
  display(s1);
  display(s2);
  
  if(isIdentical(s1,s2))
    printf("\ns1 and s2 stack content are identical\n");
  else
    printf("\ns1 and s2 stack content are not identical\n");
    
  return 0;
}