#include<stdio.h>
#include<stdlib.h>
#include "pqueue.h"

int main()
{
  int choice,size,data;
  Queue *q;
  
  printf("\nEnter size of Priority Queue:");
  scanf("%d",&size);
  q=newQueue(size);
  
  while(1)
  {
    printf("\n1.Add\n2.Remove\n3.Peek\n4.isEmpty\n5.isFull\n6.display\nEnter choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1:
      printf("\nEnter data to add:");
      scanf("%d",&data);
      printf("%d\n",add(q,data));
      break;
      
      case 2:
      printf("%d\n",dequeue(q));
      break;
      
      case 3:
      printf("%d",peek(q));
      break;
      
      case 4:
      printf("\n(True:1,False:0) queue empty:%d\n",isEmpty(q));
      break;
      
      case 5:
      printf("\n(True:1,False:0) queue full:%d\n",isFull(q));
      break;
      
      case 6:
      display(q);
      break;
      
    }
  }
  return 0;
}