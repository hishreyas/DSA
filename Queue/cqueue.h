typedef struct Node 
{
  int data;
  struct Node *next;
}Node;

typedef struct Queue
{
  Node *rear;
  
}Queue;

Node *newNode(int data,Node *next)
{
  Node *node=(Node *)(malloc(sizeof(Node)));
  node->data=data;
  node->next=next;
  
  return node;
}

Queue *newQueue()
{
  Queue *q=(Queue *)malloc(sizeof(Queue));
  q->rear=NULL;
  
  return q;
}

int isEmpty(Queue *q)
{
  return q->rear==NULL;
}

int add(Queue *q,int data)
{
  if(isEmpty(q))
  {
   q->rear=newNode(data,NULL);
   q->rear->next=q->rear;
  }
  else
   q->rear=q->rear->next=newNode(data,q->rear->next);
   
   return data;
}
int dequeue(Queue *q)
{
  Node *temp;
  if(!isEmpty(q))
  {
    if(q->rear==q->rear->next)
    {
      q->rear=NULL;
      
      return 0;
    }
    else
    {
      temp=q->rear->next;
      q->rear->next=temp->next;
      free(temp);
    }
   return q->rear->next->data;
  }
  printf("\nOperation failed:Queue is Empty:");
  return 0;
}

int peek(Queue *q)
{
  if(!isEmpty(q))
   return q->rear->next->data;
  else
  printf("\nOperation failed:Queue is Empty:");
  return 0;
}

void display(Queue *q)
{
  Node *tfront=q->rear->next;
  printf("\n");
  if(!isEmpty(q))
  {
    while(tfront!=q->rear)
    printf("%d ",tfront->data),tfront=tfront->next;
    printf("%d",tfront->data);
  }
  printf("\n");
}