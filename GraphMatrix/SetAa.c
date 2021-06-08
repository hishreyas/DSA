/*
Roll no:6
practical: Adjacency Matrix
Set A
*/

#include<stdio.h>
#include<stdlib.h>


void acceptGraph(int arr[20][20],int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      arr[i][j]=0;
      
      if(i!=j)
      {
        printf("\nis there edge between %d and %d (1:True,0:False):",i+1,j+1);
        scanf("%d",&arr[i][j]);
      }
    
    }
  }
}

void printGraph(int arr[20][20],int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%d\t",arr[i][j]);
   printf("\n");
    
  }
}

void iodeg(int arr[20][20],int n)
{
  int i,j,in=0,out=0,total=0;
  for(i=0;i<n;i++)
  {
    in=out=0;
    for(j=0;j<n;j++)
    {
      in+=arr[j][j];
      out+=arr[i][j];
      total+=arr[i][j];
    }
   printf("\nVertex:%d ,indegree=%d, outdegree=%d",i+1,in,out);
  }
  
  printf("\nTotal degree of graph:%d\n",total);
}



int main()
{
  int arr[20][20];
  int n;
  
  printf("\nEnter vertices:");
  scanf("%d",&n);
  
  acceptGraph(arr,n);
  printGraph(arr,n);
  iodeg(arr,n);
  
}