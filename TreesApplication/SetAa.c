
/*
Roll no:6
practical:Trees Application
Set A
*/



#include<stdio.h>
#include<stdlib.h>
#include"btree.h"
#include"stqueue.h"




void levelwisedisplay(Node *root)
{
  Queue *q=newQueue();
  Node *temp=root,*marker=NULL;
  int total=0,cnt=0,level=0,ended=0;
  add(q,temp);
  add(q,marker);
  printf("\nLevel %d : ",level);
  while(!isQEmpty(q))
  {
    temp=dequeue(q);
    
    if(temp!=marker)
    {
      total++;
      cnt++;
      printf("%d\t",temp->data);
      
      if(peek(q)==marker)
        printf("count :%d\n",cnt);
      if(temp->left!=NULL)
        add(q,temp->left);
      if(temp->right!=NULL)
        add(q,temp->right);
      
    }
    else
    {
      level++;
      if(!isQEmpty(q))
      {
       
       printf("\nLevel %d :",level);
       cnt=0;
       add(q,marker);
      }
    }
    
  }
  printf("\nTotal Nodes:%d",total);
}



int main()
{
  int size;
  printf("\nEnter size of bst:");
  scanf("%d",&size);
  Bst *bst=newBst(NULL);
  acceptBst(bst,size);
  printf("\nLevel wise Traversing:\n");
  levelwisedisplay(bst->root);
  
}