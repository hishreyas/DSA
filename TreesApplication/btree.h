
 typedef struct Node
{
  struct Node * left;
  struct Node * right;
  int data;
}Node;

typedef struct Bst
{
  Node *root;
}Bst;
static int count=0;
Bst *newBst(Node *root)
{
  Bst * bst=(Bst *)malloc(sizeof(Bst));
  bst->root=root;
  return bst;
}

int isEmpty(Node *root)
{
  return root==NULL;
}

Node *newNode(int data,Node * left,Node* right)
{
  Node *node=(Node *)malloc(sizeof(Node));
  node->data=data;
  node->left=left;
  node->right=right;
  return node;
}


int  insert(Bst *bst,int x)
{
  Node*root=bst->root;
  Node *temp=NULL;
  
  while(root!=NULL)
  {
    if(x<root->data)
    {
      temp=root;
      root=root->left;
    }
    else if(x>root->data)
    {
      temp=root;
      root=root->right;
    }
    else
     return 0;
     
  }
  
  if(root==NULL)
  {
    Node *node=newNode(x,NULL,NULL);
    
    if(temp!=NULL) //bst not empty
    {
      if(temp->data<x)
      temp->right=node;
      else
      temp->left=node;
    }
    else // bst empty
    bst->root=node;
    
    return 1;
  }
  else
    return 0;
}

Node *search(Bst *bst,int x)
{
  Node *root=bst->root;
  while(root!=NULL)
  {
    if(root->data==x)
    return root;
    else if(x<root->data)
    root=root->left;
    else if(x>root->data)
    root=root->right;
  }
  return root;
}

Node * min(Node *root)
{
  while(root->left!=NULL)
    root=root->left;
  return  root;
}

//iteretative approach
/*
int countBst(Node *root)
{
  int count=0;
  Node *temp1=root;
  Node *temp2=root;
  
  if(isEmpty(root)) //empty Bst
  return 0;
  
  while(temp1->left!=NULL) // counts in left 
   count++,temp1=temp1->left;
   
   while(temp2->right!=NULL) // counts in right
   count++,temp2=temp2->right;
   
   return count+1;
}
*/

//recursive
int countBst(Node *root)
{
  Node *temp=root;
  
  if(temp!=NULL)
  {
    count++;
    countBst(temp->left);
    countBst(temp->right);
  }
  return count;
}

int countLeafBst(Node *root)
{
  Node *temp=root;
  
  if(temp!=NULL)
  {
    if(temp->left==NULL && temp->right==NULL) //leaf node
     count++;
     
    countLeafBst(temp->left);
    countLeafBst(temp->right);
    

  }
  return count;
}


int clearAt(Bst *bst,int x)
{
    Node *root=bst->root;
    Node *parent=NULL;
    int found=0;
    while(root!=NULL && !found)
    {
      if(x<root->data)
      {
        parent=root;
        root=root->left;
      }
      else if(x>root->data)
      {
        parent=root;
        root=root->right;
      }
      if(root->data==x)
      found=1;
  }
  if(found)
  {
    //leaf
    if(root->left==NULL && root->right==NULL)
    {
      if(parent->left==root)
      parent->left=NULL;
      else
      parent->right=NULL;
    }
    else if(root->left!=NULL && root->right!=NULL) //two childs
    {
      Node *minNode=min(parent);
      
      parent->data=minNode->data;
      
      clearAt(bst,minNode->data);
      
    }
    else
    {
      
      if(parent->left==root)
      {
        if(root->left==NULL)
        parent->left=root->right;
        else
        root->left=root->left;
        
      }
      else if(parent->right==root)
      {
        if(root->right==NULL)
          parent->right=root->left;
        else
          parent->right=root->right;
      }
    }
   return 1;
  }
  else
  return 0;
}




void inorder(Node *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
  
}

void preorder(Node *root)
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    
  }
}
void postorder(Node *root)
{
  if(root!=NULL)
  {
    preorder(root->left);
    preorder(root->right);
    printf("%d ",root->data);
  }
}

Node * copy(Node *root)
{
  if(root!=NULL)
  {
    Node *node=newNode(root->data,copy(root->left),copy(root->right));
    return node;
  }
  else
  return  NULL;
}
int compare(Node *a,Node*b)
{
  if(a==NULL && b==NULL)
    return 1;
  else
  {
    if(a!=NULL && b!=NULL)
    {
      if(a->data==b->data)
       if(compare(a->left,b->left))
        return compare(a->right,b->right);
    }
  }
  return 0;
  
}

void mirror(Node *root)
{
  Node *node=root,*temp;
  if(node!=NULL)
  {
    if(node->left!=NULL)
      mirror(node->left);
    if(node->right!=NULL)
      mirror(node->right);
      
      temp=node->left;
      node->left=node->right;
      node->right=temp;
  }
}

void acceptBst(Bst *bst,int n)
{
  int i;
  int num;
  
  printf("\nEnter Data of size %d :",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&num);
    insert(bst,num);
  }
}

Bst *range (int start,int end,int step)
{
  Bst *bst=newBst(NULL);
  int i;
 
  for(i=start;i<=end;i+=step)
    insert(bst,i);
  
  return bst;
 
}