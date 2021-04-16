typedef struct Node
{
  int coefficient,power;
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

Node *newNode(int coefficient,int power)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->coefficient=coefficient;
    temp->power=power;
    temp->previous=NULL;
    temp->next=NULL;
    return temp;
}


DoublyList *insertAtFirst(DoublyList *list,Node* data)
{
  if(isEmpty(list))
  {
    
    Node* temp=data;
    list->head=temp;
    list->tail=temp;
  }
  else
  {
    Node *temp;
    data->previous=NULL;
    data->next=list->head;
    temp=data;
    list->head=temp;
  }
  list->size++;
  return list;
}





DoublyList *append(DoublyList *list,Node* data)
{
  if(isEmpty(list))
   return insertAtFirst(list,data);
  else
  {
    Node *ttail=list->tail;
    Node *temp=data;
    temp->previous=ttail;
    list->tail=temp;
    ttail->next=temp;
    list->size++;
  }
  return list;
}




char *substr(char *str,int start,int end)
{
  char *nstr=malloc(end-start);
  int i,j;
  
  for(i=start,j=0;j<end && str[i]!='\0';i++,j++)
    nstr[j]=str[i];
   
  nstr[j]='\0';
   return nstr;
}

DoublyList *newPoly(char *str)
{
  int i,j,coefficient,power;
  DoublyList *poly;
  Node *temp;
  
  poly=newList();
  for(i=0,j=0;str[i]!='\0'; i++)
  {
    if(isalpha(str[i]))
      coefficient=atoi(substr(str,j,i));
      
    if(i>0 && isdigit(str[i]) && str[i-1]=='+')
     j=i;
     
    if(i>0 && str[i-1]=='^')
    {
      power=str[i]-'0';
      temp=newNode(coefficient,power);
      append(poly,temp);
    }
    }
  return poly;
}
DoublyList *addPoly(DoublyList *polya,DoublyList *polyb)
{
  Node *heada;
  Node *headb;
  DoublyList *polysum;
  int sum;
  polysum=newList();
  heada=polya->head;
  
  while(heada!=NULL)
  {
    headb=polyb->head;
    sum=heada->coefficient;
    
    while(headb!=NULL)
    {
      if(heada->power==headb->power)
        sum+=headb->coefficient;
      headb=headb->next;
    }
    append(polysum,newNode(sum,heada->power));
    heada=heada->next;
  }
    return polysum;
}

DoublyList *multPoly(DoublyList *polya,DoublyList *polyb)
{
  Node *heada;
  Node *headb;
  DoublyList *polysum;
  int coe,pow;
  polysum=newList();
  heada=polya->head;
  
  while(heada!=NULL)
  {
    headb=polyb->head;
    coe=heada->coefficient;
    pow=heada->power;
    
    if(heada->coefficient==0)
    {
      heada=heada->next;
      continue;
    }
     
    while(headb!=NULL)
    {
      if(heada->power==headb->power)
      {
        pow+=headb->power;
        coe*=headb->coefficient;
      }
      headb=headb->next;
    }
    append(polysum,newNode(coe,pow));
    heada=heada->next;
  }
    return polysum;
}


void printPoly(DoublyList *list)
{
  Node *thead=list->head;
  
  while(thead!=NULL)
  {
    printf("+ %dX^%d ",thead->coefficient,thead->power);
    thead=thead->next;
  }
  printf("\n");
}

