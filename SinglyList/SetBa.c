/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
a) There are lists where insertion should ensure the ordering of data elements. Since the 
elements are in ascending order the search can terminate once equal or greater element is 
found. Implement a singly linked list of ordered integers(ascending/descending) with insert, 
search and display operations.
*/
#include<stdio.h>
#include<stdlib.h>
#include "csinglylist.h"

int ensure(int data,int previous)
{
  return data>=previous;
}
int main()
{
	SinglyList * list;
	int choice;
	int x,n,previous;
	
  list=newList();
  
	while(1)
	{
		printf("\n1.Append\n2.Search\n3.display\nEnter choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter data to append:");
				scanf("%d",&n);
				if(ensure(n,previous))
				{
			    	display(append(list,n));
			      previous=n;
				}
				else
				printf("insertion in ascending mode");
				break;
				
			case 2:
        printf("\nEnter data to search:");
        scanf("%d",&n);
				Node *result=search(list,1,n);
				if(result!=NULL)
				   printf("\nelement Found\n");
				else
				   printf("\nelement Not Found\n");
			  break;
				   
      case 3: 
        display(list);
        break;
        
			default:
			    printf("Enter valid choice");
		}

	}
	destroy(list);

}
