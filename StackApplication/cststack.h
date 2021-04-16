typedef struct Stackc
{
  int top,size;
  char *arr;
  
}Stackc;

Stackc * newStackc(int size)
{
  Stackc *stack=(Stackc *)malloc(sizeof(Stackc));
  stack->arr=(char *)malloc(sizeof(char)*size);
  stack->top=-1;
  stack->size=size;
  
  return stack;
}

int isEmptyc(Stackc *stack)
{
  return stack->top==-1;
}

int isFullc(Stackc *stack)
{
  return stack->top==stack->size-1;
}

char pushc(Stackc *stack,char data)
{
  if(isFullc(stack))
     printf("\nStack overflow: operation failed:");
  else
    return stack->arr[++stack->top]=data;
  
  return data;
}

char popc(Stackc *stack)
{
  if(isEmptyc(stack))
    printf("\nStack underflow: operation failed:");
  else
    return stack->arr[stack->top--];
    
   return ' ';
}

int peekc(Stackc *stack)
{
  if(isEmptyc(stack))
    printf("Stack empty: operation failed:");
  else
    return stack->arr[stack->top];
    
  return ' ';
}
void destroyc(Stackc *stack)
{
  free(stack);
}

void displayc(Stackc *stack)
{
  int i;
  printf("\n");
  for(i=stack->top;i>=0;i--)
    printf("%d ",stack->arr[i]);
  printf("\n");
}

int isOperator(char c)
{
  if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' ||c=='%' ||c== '^')
    return 1;
  else 
    return 0;
}

int isOperand(char c)
{
  if((c>='0' && c<='9') || (c>='A' && c<='Z') ||(c>='a' && c<='z'))
    return 1;
  else
    return 0;
}

int priority(char c)
{
  if(c=='+' || c=='-')
   return 1;
  if(c=='*' ||c=='/')
   return 2;
  if(c=='^' ||c=='$')
   return 3;
  else
   return 0;
}

void infixToPostfix(char *output,char *infix)
{
  Stackc *stack=newStackc(30);
  int i,j;
  
  
  for(i=0,j=0;infix[i]!='\0';i++)
  {
    
    if(isOperand(infix[i]))
      output[j++]=infix[i];
      
    if(infix[i]=='(')
     pushc(stack,infix[i]);
     
    if(isOperator(infix[i]))
    {
      while(!isEmptyc(stack) && priority(peekc(stack))>=priority(infix[i]))
      output[j++]=popc(stack);
      pushc(stack,infix[i]);
    }
    
    if(infix[i]==')')
    {
     while(!isEmptyc(stack) && peekc(stack)!='(')
       output[j++]=popc(stack);
      popc(stack);
    }
     
  }
  while(!isEmptyc(stack) )
    output[j++]=popc(stack);
  output[j]='\0';

  destroyc(stack);
}




char *strrev(char *rev,char *str)
{
  Stackc *stack=newStackc(40);
  int i;
  
  for(i=0;str[i]!='\0';i++)
    pushc(stack,str[i]);
  for(i=0;!isEmptyc(stack);i++)
     rev[i]=popc(stack);
  rev[i]='\0';
  
  return rev;
}

int isPalindrome(char *str)
{
  Stackc *stack=newStackc(40);
  int i,flag=1;
  
  for(i=0;str[i]!='\0';i++)
    pushc(stack,str[i]);

  i=0;
  while(!isEmptyc(stack) && str[i++]==popc(stack));
  

  return isEmptyc(stack);
}
