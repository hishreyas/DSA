#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "doublylist.h"

int main()
{
  DoublyList *list;
  int n;
  srand(time(0));
  
  list=newList();
  
  printf("\nEnter n value:");
  scanf("%d",&n);
  printf("\nGenerated List:");
  display(generate(list,n,100));
  printf("\nSorted List using insertion sort:");
  display(i_sort(list));
  
  destroy(list);
  
}