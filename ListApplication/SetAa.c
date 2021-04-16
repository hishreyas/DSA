#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include "doublylist.h"

int main()
{
  DoublyList *list1;
  DoublyList *list2;
  DoublyList *listm;
  int start,end,step;
  list1=newList();
  list2=newList();
  
  printf("\nEnter List 1 start,end,step size:");
  scanf("%d%d%d",&start,&end,&step);
  printf("\nList 1:");
  display(range(list1,start,end,step));
  printf("\nEnter List 2 size,range,step:");
  scanf("%d%d%d",&start,&end,&step);
  printf("\nList 2:");
  display(range(list2,start,end,step));
  printf("\nMerged List:");
  listm=merge(list1,list2);
  display(listm);
  
  destroy(list1);
  destroy(list2);
  destroy(listm);
}