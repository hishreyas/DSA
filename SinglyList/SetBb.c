/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
b) There are lists where new elements are always appended at the end of the list. The list can 
be implemented as a circular list with the external pointer pointing to the last element of the 
list. Implement singly linked circular list of integers with append and display operations. The 
operation append(L, n), appends to the end of the list, n integers either accepted from user or 
randomly generated.
*/
#include<stdio.h>
#include<stdlib.h>
#include "csinglylist.h"

int main()
{
	SinglyList * list,*rev;
	
	list=newList();
	range(list,2,20,2); //2 4 6..20
	display(list);

	destroy(list);
}
