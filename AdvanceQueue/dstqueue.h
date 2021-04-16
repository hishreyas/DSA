typedef struct Queue
{
  int front,rear,size;
  int *arr;
}Queue;

Queue *newQueue(int size)
{
  Queue *q=(Queue *)malloc(sizeof(Queue));
  q->front=-1;
  q->rear=0;
  q->arr=(int *)malloc(sizeof(int));
  q->size=size;
  
  return q;
}

int isEmpty(Queue *q)
{
  return q->front==-1 ;
}
int isFull(Queue *q)
{
  return ((q->front==0) && (q->rear==q->size-1)) || q->front==q->rear+1;
}
int addR(Queue *q,int data)
{
  
  if(isFull(q))
  {
    printf("\nQueue Overflow: operation failed:");
    return 0;
  }
  
  
  if(q->front==-1)
    q->front=q->rear=0;
  else if(q->rear==q->size-1)
   q->rear=0;
  else
  q->rear++;
  q->arr[q->rear]=data;
  return data;
}

int addF(Queue *q,int data)
{
  
  if(isFull(q))
  {
    printf("\nQueue Overflow: operation failed:");
    return 0;
  }
  
  if(q->front==-1)
   q->front=q->rear=0;
  else if(q->front==0)
   q->front=q->size-1;
  else
   --q->front;
  q->arr[q->front]=data;
  return q->arr[q->front];
}

int dequeueF(Queue *q)
{
  int data;
  if (isEmpty(q))
  {
    printf("Queue Underflow\n");
    return 0;
  }
  
  if(q->rear==q->front)
  {
    data=q->arr[q->front];
    q->arr[q->front]=0;
    q->rear=q->front=-1;
  }
  else
  {
     if(q->front==q->size-1)
     {
       data=q->arr[q->front];
       q->arr[q->front]=0;
       q->front=0;
     }
     else
     {
       data=q->arr[q->front];
       q->arr[q->front]=0;
       q->front++;
     }
  }
   return data;
}

int dequeueR(Queue *q)
{
  int data;
  if(isEmpty(q))
  {
    printf("Queue Underflow\n");
    return 0;
  }
  if (q->front == q->rear)
  {
    data=q->arr[q->front];
    q->arr[q->front]=0;
    q->front=q->front = -1;
  }
    
  else if (q->rear == 0)
  {
       data=q->arr[q->rear];
       q->arr[q->rear]=0;
       q->rear=q->size-1;
       return data;
  }
  else
  {
    data=q->arr[q->rear];
    q->arr[q->rear]=0;
    q->rear--;
  }
   
  return data;
}

int getFront(Queue *q)
{
  if(isEmpty(q))
  {
    printf("Queue Underflow :operation failed:");
    return 0;
  }
  return q->arr[q->front];
}

int getRear(Queue *q)
{
  if(isEmpty(q) || q->rear<0)
  {
    printf("Queue Underflow: operation failed:");
    return 0;
  }
  return q->arr[q->rear];
}

void display(Queue *q)
{
  int i=0;
  
  printf("\n");
  while(i<q->size)
  {
    // to emitate dqueue eliminate 0 value
    if(q->arr[i]!=0)
    printf("%d ",q->arr[i]);
    i++;
  }
  printf("\n");
}