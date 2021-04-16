typedef struct Node 
{
  int data;
  struct Node *next;
}Node;

typedef struct Queue
{
  Node *front,*rear;
  
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
  q->front=q->rear=NULL;
  
  return q;
}

int isEmpty(Queue *q)
{
  return q->front==NULL;
}

int add(Queue *q,int data)
{
  if(isEmpty(q))
  {
   q->front=q->rear=newNode(data,NULL);
  }
  else
   q->rear=q->rear->next=newNode(data,NULL);
   
   return data;
}
int dequeue (Queue *q)
{
  Node *temp;
  if(!isEmpty(q))
  {
    if(q->rear==q->front)
    {
      q->rear=q->front=NULL;
      return 0;
    }
    else
    {
      temp=q->front;
      q->front=q->front->next;
      free(temp);
    }
   return q->front->data;
  }
  printf("\nOperation failed:Queue is Empty:");
  return 0;
}

int peek(Queue *q)
{
  if(!isEmpty(q))
   return q->front->data;
  else
  printf("\nOperation failed:Queue is Empty:");
  return 0;
}

void display(Queue *q)
{
  Node *tfront=q->front;
  printf("\n");
  while(tfront!=NULL)
   printf("%d ",tfront->data),tfront=tfront->next;
  printf("\n");
}

void reverse(Node *front)
{
  if(front==NULL)
     return;
  else
   reverse(front->next);
   
  printf("%d ",front->data);
 }

Queue *range(int start,int end,int step)
{
  int i;
  Queue *q=newQueue();
  
  for(i=start;i<=end;i+=step)
    add(q,i);
    
  return q;
}
