/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A,
a) Implement a list library (doublylist.h) for a doubly linked list with the above four 
operations. Write a menu driven driver program to call the operationsappend, insert, delete 
specific node, delete at position, search, display.
*/
#include<stdio.h>
#include<stdlib.h>
#include "cdoublylist.h"

int main()
{
	DoublyList * list;
	int choice;
	int x,n;

	list=newList();

	while(1)
	{
		printf("\n1.Append\n2.Insert at\n3.Search\n4.Delete\n5.Delete at\n6.Display\nEnter choice:");

		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter data to append:");
				scanf("%d",&n);
				display(append(list,n));
				break;
				
			case 2:

				printf("\nEnter data & postion value to insert::");
				scanf("%d%d",&n,&x);
				display(insert(list,n,x));

				break;
				
			case 3:
        printf("\nEnter data to search:");
        scanf("%d",&n);
				Node *result=search(list,n,0);
				if(result!=NULL)
				   printf("\nelement Found\n");
				else
				   printf("\nelement Not Found\n");

        break;
        
			case 4:
        printf("\nEnter data to delete element:");
				scanf("%d",&n);
				display(clear(list,n));
         break;
         
			case 5:

        printf("\nEnter postion value to delete element:");
        scanf("%d",&x);
				display(clearAt(list,x));
        break;
        
			case 6:
        display(list);
        break;
      
			default:
			    printf("Enter valid choice");

		}

	}
	destroy(list);

}
