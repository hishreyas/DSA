typedef struct Node 
{
  int data;
  struct Node *next;
}Node;

typedef struct Stack
{
  Node *top;
  
}Stack;

int isEmpty(Stack *stack)
{
  return stack->top==NULL;
}

int getSize(Stack *stack)
{
  int i;
  Node *ttop;
  
  for(ttop=stack->top,i=-1;ttop!=NULL;ttop=ttop->next,i++);
  
  return i+1;
}


Stack * newStack()
{
  Stack *stack=(Stack *)malloc(sizeof(Stack));
  stack->top=NULL;
  
  return stack;
}

Node *newNode(int data,Node *next)
{
  Node *node=(Node *)(malloc(sizeof(Node)));
  node->data=data;
  node->next=next;
  
  return node;
}

int push(Stack *stack,int data)
{
  stack->top=newNode(data,stack->top);
  return stack->top->data;
}

int pop(Stack *stack)
{
  int data=-1;
  if(isEmpty(stack))
   printf("\nStack underflow: operation failed:");
  else
  {
   Node *temp=stack->top;
   stack->top=stack->top->next;
   data=temp->data;
   free(temp);
  }
  return data;
}
int peek(Stack *stack)
{
  if(isEmpty(stack))
    printf("\nEmpty stack: operation failed:");
  else
  return stack->top->data;
  
  return -1;
}
void display(Stack *stack)
{
  Node *ttop=stack->top;
  
  printf("\n");
  while(ttop!=NULL)
   printf("%d ",ttop->data),ttop=ttop->next;
  
  printf("\n");
}



Stack * stackCpy(Stack *s1,Stack *s2)
{
  Stack *temp=newStack();
  Node* ttop=s2->top;
  
  while(ttop!=NULL)
   push(temp,ttop->data),ttop=ttop->next;
  
  while(!isEmpty(temp))
   push(s1,pop(temp));
   
   return s1;
}

int isIdentical(Stack *s1,Stack *s2)
{
  Stack *t1,*t2;
  t1=newStack();
  t2=newStack();
  stackCpy(t1,s1);
  stackCpy(t2,s2);
  
  if(getSize(t1)!=getSize(t2))
   return 0;
  else
  {
    while(!isEmpty(t1) && !isEmpty(t2))
    {
      if(pop(t1)!=pop(t2))
        return 0;
    }
    return 1;
  }
}
Stack *range(int start,int end,int step)
{
  int i;
  Stack *stack=newStack();
  
  for(i=start;i<=end;i+=step)
    push(stack,i);
    
  return stack;
}
