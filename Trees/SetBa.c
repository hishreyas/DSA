#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

/*
Assignment:1 BST and Traversal
Roll No:6
Question:Set B a
*/


int main()
{
  Bst *bst=range(2,20,2); //20..18..16...20
  
  printf("\nBst inorder:");
  inorder(bst->root);
  printf("\n");
  
  Bst *copied=newBst(copy(bst->root));
  printf("\nCopied Bst inorder:");
  inorder(copied->root);
  printf("\n");
  
  
  if(compare (bst->root,copied->root))
  printf("\nBst and Copied Bst are identical\n");
  else
  printf("\nBst and Copied Bst not are identical\n");
  
  
  printf("\nDifferent Bst and original Bst comparison\n");
  
  Bst *diff=range(3,30,3); // 3..9..30
  
  printf("\nDifferent Bst inorder:");
  inorder(diff->root);
  printf("\n");
  
  if(compare (bst->root,diff->root))
  printf("\nBst and Copied Bst are identical\n");
  else
  printf("\nBst and Copied Bst not are identical\n");
  
  
  
}