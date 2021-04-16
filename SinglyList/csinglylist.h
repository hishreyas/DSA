typedef struct Node
{
        int data;
        struct Node *next;
}Node;

typedef struct SinglyList
{
  Node* head;
  Node* tail;
	int size;
}SinglyList;

SinglyList *newList()
{
	SinglyList *list=(SinglyList *)malloc(sizeof(SinglyList));
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
	return list;
}

Node* newNode(int data,Node *next)
{
  Node *node=(Node *)malloc(sizeof(Node));
  node->data=data;
  node->next=next;
  return node;
}

int isEmpty(SinglyList* list)
{
  return list->head==NULL;
}

SinglyList *insertAtFirst(SinglyList *list,int data)
{
  if(isEmpty(list))
  {
    Node *tnode=newNode(data,list->head);
    list->head=tnode;
    tnode->next=list->head;
    list->tail=tnode;
  }
  else
  {
    Node *tnode=newNode(data,list->head);
    list->head=tnode;
    list->tail->next=list->head;
  }
  list->size++;
  return list;
}
SinglyList *clearAtFirst(SinglyList* list)
{
  if(!isEmpty(list))
  {
    Node* thead=list->head;
    if(thead->next==NULL || thead->next==thead)
    {
      free(thead);
      free(list->tail);
      list->head=NULL;
      list->tail=NULL;
    }
    else
    {
      Node *nhead=list->head->next;
      free(list->head);
      list->head=nhead;
      list->tail->next=list->head;
    }
    list->size--;
  }
  return list;
}
SinglyList *clearAtLast(SinglyList *list)
{
  if(!isEmpty(list))
  {
    Node* thead=list->head;
    if(thead->next==NULL || thead->next==thead)
    {
      free(thead);
      free(list->tail);
      list->head=NULL;
      list->tail=NULL;
    }
    else
    {
      while(thead->next!=list->tail)
        thead=thead->next;
       free(thead->next);
       thead->next=list->head;
       list->tail=thead;
      }
    list->size--;
  }
  return list;
}

SinglyList*clearNode(SinglyList*list,Node*thead)
{
  if(thead!=NULL)
 {
   Node* datan=thead->next;
   Node *next=datan->next;
   free(datan);
   thead->next=next;
   next->next=list->head;
   list->tail=next;
   list->size--;
  }
   return list;
}
SinglyList* append(SinglyList* list,int data)
{
  if(isEmpty(list))
   return insertAtFirst(list,data);
  else
  {
    list->tail->next=newNode(data,list->head);
    list->tail=list->tail->next;
  }
  list->size++;
  return list;
}

SinglyList *insert(SinglyList *list,int data,int pos)
{
  if(isEmpty(list) || pos>=list->size)
   return append(list,data);
  else if(pos==0)
   return insertAtFirst(list,data);
  else
  {
    Node *thead=list->head;
    int i=0;
    
    while (i++<pos-1)
      thead=thead->next;
     
    thead->next=newNode(data,thead->next);
  }
 list->size++;
 return list;
}
SinglyList *clear(SinglyList*list,int data)
{
  if(!isEmpty(list))
  {
    Node *temp=list->head;
    
    if(temp->data==data)
     return clearAtFirst(list);
    else
    {
      while(temp->next->data!=data && ( temp->next!=list->tail))
			   temp=temp->next;
			   
		 if(temp->next->data==data)
        clearNode(list,temp);
    }
  }
  return list;
}
SinglyList *clearAt(SinglyList* list,int pos)
{
  if(!isEmpty(list) && pos<list->size)
  {
    if(pos==0)
     return clearAtFirst(list);
    else
    {
      Node * pre=list->head;
      int i=0;
      while(i++<pos-1)
      pre=pre->next;
      Node *next=pre->next->next;
      free(pre->next);
      pre->next=NULL;
      
      if(next==list->head)
       list->tail=pre;
       
       pre->next=next;
       list->size--; 
   
    }
  }
  return list;
}
Node *search(SinglyList *list,int asc,int key)
{
  if(list==NULL)
    return NULL;
	Node *temp=list->head;
	
	while(temp!=list->tail && (asc ? temp->data!=key:temp->data<=key) )
		temp=temp->next;

	return temp;
}
int display(SinglyList *list)
{
  Node *thead=list->head;
  
  printf("\n");
//  printf("%d ",thead->data);
//  thead=thead->next;
  while(thead!=list->tail)
  {
    printf("%d ",thead->data);
    thead=thead->next;
  }
  if(thead!=NULL)
  printf("%d\t",thead->data);
  
  printf("\n");
  return list->size;
}
int destroy(SinglyList *list)
{
	int i;
	if(list==NULL)
		return 0;

	int size=list->size;
	for(i=0;i<size;i++)
		clearAt(list,0);

	free(list);
	return 1;
}
SinglyList * reverse(SinglyList *list)
{
	Node *current=list->head;
	Node *previous=NULL;
	Node *next;
	Node *tail=list->head;
	
	while(current!=list->tail)
	{
		next=current->next;
		if(next!=list->tail)
		{
		  current->next=previous;
			previous=current;
			current=next;
		}
		else
		{
			list->head=current;
			current->next=previous;
			previous=current;
			current=next;
		}
	}
	
	list->head=current;
  current->next=previous;
  list->tail=tail;
	list->tail->next=list->head;
	
	return list;
}
/*
Functions uses see Singlylist type of LinkedList
*/
SinglyList *range(SinglyList *list,int start,int end,int step)
{
  int i;
  
  for(i=start;i<end;i+=step)
    append(list,i);
  return list;
}
