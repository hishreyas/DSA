#define MAX_SIZE 100

typedef struct Queue
{
  int front,rear,size;
  Node *arr[MAX_SIZE];
}Queue;

Queue *newQueue()
{
  Queue *q=(Queue *)malloc(sizeof(Queue));
  q->front=q->rear=-1;
 
  
  return q;
}

int isQEmpty(Queue *q)
{
  return q->front==q->rear;
}

int isQFull(Queue *q)
{
  return q->rear==MAX_SIZE-1;
}

void add(Queue *q,Node *data)
{
  if(!isQFull(q))
   q->arr[++q->rear]=data;
  else
   printf("\nOperation failed:Queue is Full");
}

Node * dequeue(Queue *q)
{
  if(!isQEmpty(q))
  return q->arr[++q->front];
  else
  printf("\nOperation failed:Queue is Empty:");
  return NULL;
}

Node* peek(Queue *q)
{
  if(!isQEmpty(q))
   return q->arr[q->front+1];
  else
  printf("\nOperation failed:Queue is Empty:");
  return NULL;
}