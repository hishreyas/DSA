typedef struct Stack
{
  int top,size;
  int *arr;
  
}Stack;

Stack * newStack(int size)
{
  Stack *stack=(Stack *)malloc(sizeof(Stack));
  stack->arr=(int *)malloc(sizeof(int)*size);
  stack->top=-1;
  stack->size=size;
  
  return stack;
}

int isEmpty(Stack *stack)
{
  return stack->top==-1;
}

int isFull(Stack *stack)
{
  return stack->top==stack->size-1;
}

int push(Stack *stack,int data)
{
  if(isFull(stack))
     printf("\nStack overflow: operation failed:");
  else
    return stack->arr[++stack->top]=data;
  
  return data;
}

int pop(Stack *stack)
{
  if(isEmpty(stack))
    printf("\nStack underflow: operation failed:");
  else
    return stack->arr[stack->top--];
    
   return -1;
}

int peek(Stack *stack)
{
  if(isEmpty(stack))
    printf("Stack empty: operation failed:");
  else
    return stack->arr[stack->top];
    
  return -1;
}
void destroy(Stack *stack)
{
  free(stack);
}

void display(Stack *stack)
{
  int i;
  printf("\n");
  for(i=stack->top;i>=0;i--)
    printf("%d ",stack->arr[i]);
  printf("\n");
}
