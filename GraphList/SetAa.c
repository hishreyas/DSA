
/*
Roll no:6
practical: Adjacency List
Set A
*/





#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int vertex;
struct node *next;
} NODE;




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
    printf("\nIs there an edge between %d and %d (1/0) : ", i+1,j+1);
    scanf("%d",&m[i][j]);
    }
  }
}

void createlist(int m[10][10], int n)
{
  int i, j;
  struct node *last, *newnode;
  for(i=0; i<n;i++)
  {
    for(j=0;j<n;j++)
  {
    if(m[i][j]==1)
    {
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->vertex=j+1;
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

void displist(int n)
{
  struct node *temp;
  int i;
  printf("\nThe adjacency list is :\n");
for(i=0;i<n;i++)
  {
  printf("\nv%d->",i+1);
  temp=list[i];
  while(temp)
  {
    printf("v%d -> ",temp->vertex);
    temp=temp->next;
  }
  printf("NULL");
  }
}


void iodeg(int arr [10][10],int n)
{
  int i,j,in=0,out=0,total=0;
  for(i=0;i<n;i++)
  {
    in=out=0;
    for(j=0;j<n;j++)
    {
      in+=arr[j][i];
      out+=arr[i][j];
      total+=arr[i][j];
    }
   printf("\nVertex:%d ,indegree=%d, outdegree=%d",i+1,in,out);
  }
  printf("\nTotal degree of graph:%d\n",total);
}


void main()
{
  int m[10][10],arr,n;
printf("\n Enter the number of vertices :");
  scanf("%d",&n);
  createmat(m,n);
  dispmat(m,n);
  createlist(m,n);
  iodeg(m,n);
  displist(n);
}

