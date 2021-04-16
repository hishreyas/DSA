#include<stdio.h>
#include<stdlib.h>
#include "dstqueue.h"

int main()
{
  int choice,size,data;
  Queue *q;
  
  printf("\nEnter size of Priority Queue:");
  scanf("%d",&size);
  q=newQueue(size);
  
  while(1)
  {
    printf("\n1.Add Front\n2.Add Rear\n3.Remove Front\n4.Remove Rear\n5.getFront\n6.getRear\n7.isEmpty\n8.isFull\n9.display\nEnter choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1:
      printf("\nEnter data to add:");
      scanf("%d",&data);
      printf("%d\n",addF(q,data));
      break;
      
      case 2:
      printf("\nEnter data to add:");
      scanf("%d",&data);
      printf("%d\n",addR(q,data));
      break;
      
      case 3:
      printf("%d",dequeueF(q));
      break;
      
      case 4:
        printf("%d",dequeueR(q));
      break;
      
      case 5:
      printf("\nFront=%d\n",getFront(q));
      break;
      
      case 6:
      printf("\nRear=%d\n",getRear(q));
      break;
      
      case 7:
      printf("\n(True:1,False:0) queue empty:%d\n",isEmpty(q));
      break;
      
      case 8:
      printf("\n(True:1,False:0) queue full:%d\n",isFull(q));
      break;
      
      case 9:
      display(q);
      break;
      
    }
  }
  return 0;
}