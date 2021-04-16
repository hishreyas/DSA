typedef struct Node
{
  int data;
  struct Node * previous;
  struct Node * next;
}Node;

typedef struct DoublyList
{
  Node *head;
  Node *tail;
  int size;
}DoublyList;

DoublyList *newList()
{
  DoublyList*list=(DoublyList*)malloc(sizeof(DoublyList));
  list->head=NULL;
  list->tail=NULL;
  list->size=0;
  return list;
}

int isEmpty(DoublyList *list)
{
  return list->head==NULL;
}

Node *newNode(int data,Node*pre,Node*next)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->previous=pre;
    temp->next=next;
    return temp;
}

DoublyList *insertAtFirst(DoublyList *list,int data)
{
  if(isEmpty(list))
  {
    Node* temp=newNode(data,NULL,NULL);
    list->head=temp;
    list->tail=temp;
  }
  else
  {
    Node* temp=newNode(data,NULL,list->head);
    list->head->previous=temp;
    list->head=temp;
  }
  list->size++;
  return list;
}

DoublyList *clearAtFirst(DoublyList* list)
{
  if(!isEmpty(list))
  {
    Node *thead=list->head;
    if(thead->next==NULL)
    {
      free(thead);
      free(list->tail);
      list->head=NULL;
      list->tail=NULL;
    }
    else
    {
      list->head=list->head->next;
      list->head->previous=NULL;
    }
  }
  list->size--;
  return list;
}

DoublyList *clearAtLast(DoublyList *list)
{
  if(!isEmpty(list))
  {
    Node *thead=list->head;
    if(thead->next==NULL)
    {
      free(thead);
      free(list->tail);
      list->head=NULL;
      list->tail=NULL;
    }
    else
    {
      Node *ttail=list->tail;
      Node *pre=ttail->previous;
      free(ttail);
      pre->next=NULL;
      list->tail=pre;
    }
  }
  list->size--;
  return list;
}

DoublyList *clearNode(DoublyList *list,Node *thead)
{
  if(thead!=NULL)
    {
      if(thead->next==NULL)
       return  clearAtLast(list);
      else if(thead==list->head)
       return clearAtFirst(list);
      else
      {
        Node *pre=thead->previous;
        Node *next=thead->next;
        pre->next=next;
        next->previous=pre;
        free(thead);
        list->size--;
       }
    }
    return list;
}

DoublyList *append(DoublyList *list,int data)
{
  if(isEmpty(list))
   return insertAtFirst(list,data);
  else
  {
    Node *ttail=list->tail;
    Node* temp=newNode(data,ttail,NULL);
    ttail->next=temp;
    list->tail=temp;
    list->size++;
  }
  return list;
}

DoublyList *insert(DoublyList *list,int data,int pos)
{
  if(isEmpty(list) ||pos>list->size)
    return append(list,data);
  else if(pos==0)
  return insertAtFirst(list,data);
  else
  {
    Node* thead=list->head;
    int i=0;
    while(i<pos-1 && thead!=NULL)
    {
      thead=thead->next;
      i++;
    }
    Node *temp=newNode(data,thead,thead->next);
    thead->next=temp;
    thead->next->next->previous=temp;
    list->size++;
  }
  return list;
}

DoublyList *clear(DoublyList *list,int data)
{
  if(!isEmpty(list))
  {
    Node *thead=list->head;
    
    while(thead!=NULL && thead->data!=data)
      thead=thead->next;
      
   return clearNode(list,thead);
}
return list;
}

DoublyList *clearAt(DoublyList *list,int pos)
{
  if(!isEmpty(list))
  {
    int i=0;
    Node *thead=list->head;
    while(i!=pos && thead!=NULL)
    {
      thead=thead->next;
      i++;
    }
      return clearNode(list,thead);
  }
  return list;
}

Node *search(DoublyList *list,int key,int asc)
{
  Node *thead=list->head;
  
  while(thead!=list->tail && (!asc? thead->data!=key:thead->data<key))
    thead=thead->next;
    
    if(thead->data==key)
       return thead;
    else
       return NULL;
}

int display(DoublyList *list)
{
  Node *thead=list->head;
  
  printf("\n");
  while(thead!=NULL)
  {
    printf("%d ",thead->data);
    thead=thead->next;
  }
  printf("\n");
  
  return list->size;
}

int reverse(DoublyList *list)
{
  Node *ttail=list->tail;
  
  printf("\n");
  while(ttail!=NULL)
  {
    printf("%d ",ttail->data);
    ttail=ttail->previous;
  }
  printf("\n");
  return list->size;
}

int destroy(DoublyList *list)
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
DoublyList *range(DoublyList *list,int start,int end,int step)
{
  int i;
  
  for(i=start;i<end;i+=step)
    append(list,i);
  return list;
}
DoublyList * merge(DoublyList *lista, DoublyList *listb)
{
  DoublyList *listc=newList();
  Node *heada=lista->head;
  Node *headb=listb->head;
  
  while(heada!=NULL && headb!=NULL)
  {
    if(heada->data<headb->data)
     {
       append(listc,heada->data);
       heada=heada->next;
     }
    else
    {
      append(listc,headb->data);
       headb=headb->next;
    }
  }
  while(heada!=NULL)
  {
    append(listc,heada->data);
    heada=heada->next;
  }
  while (headb!=NULL)
  {
    append(listc,headb->data);
    headb=headb->next;
  }
  
  return listc;
}
DoublyList *i_sort(DoublyList *list)
{
  Node *i=list->head->next;
  Node *j;
  int temp;
  for(i=list->head->next; i!=NULL; i=i->next)
  {
    temp=i->data;
    
    for(j=i->previous;(j!=NULL && temp<j->data); j=j->previous)
      j->next->data=j->data;
    
    if(j==NULL)
      list->head->data=temp;
    else
    j->next->data=temp;
  }
  return list;
}