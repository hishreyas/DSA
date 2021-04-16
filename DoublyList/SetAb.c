/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A,
b) Implement a list library (doublylist.h) for a doubly linked list. Create a linked list, reverse 
it and display reversed linked list.
*/
#include<stdio.h>
#include<stdlib.h>
#include "doublylist.h"

int main()
{
	DoublyList * list,*rev;
	
	list=newList();
	range(list,2,20,2); //2 4 6..20
	display(list);
	reverse(list);
	
	destroy(list);
}
