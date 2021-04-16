/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set ,
b) Implement a stack library (dystack.h) of integers using a dynamic (linked list) 
implementation of the stack and implementing the above five operations. Write a driver 
program that includes stack library and calls different stackoperations.
*/

#include<stdio.h>
#include<stdlib.h>
#include "dystack.h"

int main()
{
  int choice,data;
  Stack *stack;
  
  stack=newStack();
  
  while(1)
  {
    printf("\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.display\nEnter choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1:
      printf("\nEnter data to push:");
      scanf("%d",&data);
      printf("%d\n",push(stack,data));
      break;
      
      case 2:
      printf("%d\n",pop(stack));
      break;
      
      case 3:
      printf("%d",peek(stack));
      break;
      
      case 4:
      printf("\n(True:1,False:0) stack empty:%d\n",isEmpty(stack));
      break;
     
      case 5:
      display(stack);
      break;
      
    }
  }
  
  
  
  return 0;
}