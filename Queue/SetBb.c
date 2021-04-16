#include<stdio.h>
#include<stdlib.h>
#include "dyqueue.h"

int main()
{
  int choice,data;
  Queue *q,*r;
  
  q=range(2,20,2); //2 4 6..20
  
  printf("\nQueue:");
  display(q);
  printf("\nReverse:\n");
  reverse(q->front);
  printf("\n");
 
  return 0;
}