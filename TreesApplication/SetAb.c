
/*
Roll no:6
practical:Trees Application
Set B
*/


#include<stdio.h>
#include<stdlib.h>


void printarr(int *arr,int n)
{
  int i;
  for(i=0;i<n;i++)
  printf(" %d ",arr[i]);
  printf("\n");
}

int * generate_arr(int n)
{
  int i;
  int * arr=(int *)malloc(sizeof(int)*n);
  
  for(i=0;i<n;i++)
  arr[i]=rand()%100;

  return arr;
}

void swap(int *arr,int i,int j)
{
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}
void heapify(int *arr,int n,int i)
{
  int large=i; //root
  int l=2*i+1; //left
  int r=2*i+2; //right
  
  if(l<n && arr[l]>arr[large])
  large=l;
  
  if(r<n && arr[r]>arr[large])
  large=r;
  
  if(large!=i)
  {
    swap(arr,i,large);
    heapify(arr,n,large);
  }
}

void heapSort(int *arr,int n)
{
  int i;
  
  for(i=(n/2)-1; i>=0;i-- ) //build heap
     heapify(arr,n,i);
     
     
  for(i=n-1;i>0;i--)
  {
    swap(arr,i,0);
    heapify(arr,i,0);
  }
    
}

int main()
{
  int n;
  int *arr;
  
  printf("\nEnter number :");
  scanf("%d",&n);
  
  arr=generate_arr(n);
  
  printf("\n\nRandom array:");
  printarr(arr,n);
 
  heapSort(arr,n);
  
  printf("\n\nSorted array using Heap sort:");
  printarr(arr,n);
  
}