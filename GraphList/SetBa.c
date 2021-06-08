/*

Roll no:6
practical: Adjacency List
Set B
*/


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

typedef struct node
{
int vertex;
struct node *next;
} NODE;

typedef struct
{
  int data[MAXSIZE];
int front, rear;
} QUEUE;
void addq(QUEUE *pq, int n)
{
pq->data[++pq->rear]=n;
}
int removeq(QUEUE *pq)
{
return pq->data[++pq->front];
}
void initq(QUEUE *pq)
{
  pq->front= pq->rear=-1;
}
int isempty(QUEUE *pq)
{
  return (pq->rear== pq->front);
}

NODE *list[10] = {NULL};  //array of pointers

void createmat(int m[10][10], int n)
{
  int i,j;
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
  m[i][i]=0;
  if(i!=j)
    {
    printf("\nIs there an edge between %d and %d (True:1/False:0) : ", i+1,j+1);
    scanf("%d",&m[i][j]);
    }
  }
}

void dispmat(int m[10][10], int n)
{
  int i,j;
  printf("\nThe adjacency matrix is :\n");
  for(i=0;i<n;i++)
  {
  for(j=0;j<n;j++)
    printf("%5d",m[i][j]);
  printf("\n");
  }
}
void createlist(int m[10][10], int n)
{
  int i, j;
  NODE *last, *newnode;
  for(i=0; i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(m[i][j]==1)
    {
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->vertex=j;
    newnode->next=NULL;
    if(list[i]==NULL)
          list[i]=last=newnode;
    else
    {
         last->next=newnode;
         last=newnode;
    }
    }
  }
}
}
void displist(int n)
{
  NODE *temp;
  int i;
  printf("\nThe adjacency list is :\n");
 for(i=0;i<n;i++) //list number
  {
    printf("\nList for v%d : ",i+1);
    for(temp=list[i];temp!=NULL; temp=temp->next)
       printf("v%d -> ",temp->vertex+1);
    printf("NULL");
  }
}
void recdfs(int v)
{
  // v is the starting vertex
  NODE *temp;
  static int visited[20]={0};
  visited[v]=1; /* Mark v visited */
  printf("v%d ",v+1);
  for(temp=list[v]; temp!=NULL; temp=temp->next)  //scan all vertices
     if(visited[temp->vertex]==0)  /* not visited*/
   recdfs(temp->vertex);
}

void bfs( int v)
{
  int i,j;
  NODE *temp;
  int visited[20] = {0};
  QUEUE q;
  initq(&q);
  printf("\nThe Breadth first traversal is : ");

  visited[v]=1;
  addq(&q,v);
  while(!isempty(&q))
  {
    v=removeq(&q);
    printf(" v%d ",v+1);
    for(temp=list[v]; temp!=NULL; temp=temp->next)
    if(visited[temp->vertex]==0)
{
                   addq(&q,temp->vertex);
       visited[temp->vertex]=1;
}
  }
}

void main()
{
  int m[10][10], n;
  printf("\n Enter the number of vertices :");
  scanf("%d",&n);
  createmat(m,n);
  dispmat(m,n);
  createlist(m,n);
  displist(n);
  printf("\n\nThe Depth First Search traversal is :");
  recdfs(0);
  bfs(0);
}
