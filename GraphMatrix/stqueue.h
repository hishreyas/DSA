
typedef struct Queue
{
  int front,rear,size;
  int *arr;
}Queue;

Queue *newQueue(int size)
{
  Queue *q=(Queue *)malloc(sizeof(Queue));
  q->front=q->rear=-1;
  q->arr=(int *)malloc(sizeof(int));
  q->size=size;
  
  return q;
}

int isEmpty(Queue *q)
{
  return q->front==q->rear;
}

int isFull(Queue *q)
{
  return q->rear==q->size-1;
}

int add(Queue *q,int data)
{
  if(!isFull(q))
   return q->arr[++q->rear]=data;
  else
   printf("\nOperation failed:Queue is Full");
  return 0;
}

int dequeue(Queue *q)
{
  if(!isEmpty(q))
  return q->arr[++q->front];
  else
  printf("\nOperation failed:Queue is Empty:");
  return 0;
}

int peek(Queue *q)
{
  if(!isEmpty(q))
   return q->arr[q->front+1];
  else
  printf("\nOperation failed:Queue is Empty:");
  return -1;
}

void display(Queue *q)
{
  int i=q->front+1;
  
  printf("\n");
  while(i<=q->rear)
   printf("%d ",q->arr[i]),i++;
  printf("\n");
}