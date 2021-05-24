
/*
Assignment:1 BST and Traversal
Roll No:6
Question:Set A a,b
*/

#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

int main()
{
  Bst *bst=newBst(NULL); // create Bst
  int choice=-1;
  int num=0;
  
  while(1)
  {
    printf("\n\nBST operation :\n1.insert\n2.search\n3.inorder\n4.preorder\n5.postorder\n6.count\n7.count leaf\nChoice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1:
      
      printf("\nEnter number to insert:");
      scanf("%d",&num);
      int task=insert(bst,num);
      if(task)
      printf("\nInserted successfully\n");
      else
      printf("\nInsertion Failed duplicate data\n");
      
      break;
      
      
      case 2:
      
      printf("\nEnter number to search:");
      scanf("%d",&num);
      Node *result=search(bst,num);
      if(result!=NULL)
      printf("\nNumber found in tree :%d\n", result->data);
      else
      printf("\nNumber not found in tree\n");
      
      break;
 
      case 3:
      printf("\nInorder:");
      inorder(bst->root);
      break;
      
      case 4:
      printf("\nPreorder:");
      preorder(bst->root);
      printf("\n");
      break;
      
      case 5:
      printf("\nPostorder:");
      postorder(bst->root);
      printf("\n");
      break;
      
      case 6:
      count=0;
      printf("\nTotal Node:%d\n",countBst(bst->root));
      break;
      
      case 7:
      count=0;
      printf("\nTotal leaf Node:%d\n",countLeafBst(bst->root));
      break;
      
      default:
      printf("\nEnter vaild choice\n");
    
    }
  }
 
  
  
}