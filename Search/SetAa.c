
/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
a)Create a random array of n integers. Accept a value x from user and use linear search 
algorithm to check whether the number is present in the array or not and output the position if 
the number is present
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int * generate_arr(int n)
{
  int i;
  int * arr=(int *)malloc(sizeof(int)*n);
  
  for(i=0;i<n;i++)
  arr[i]=rand()%100;

  return arr;
}

void printarr(int *arr,int n)
{
  int i;
  for(i=0;i<n;i++)
  printf(" %d ",arr[i]);
  printf("\n");
}

int l_search(int *arr,int n,int key)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
           return i;
    }
    return -1;
}

int main()
{
    int *arr;
    int key,index,n;
    
    srand(time(0));
    
   
        printf("\nEnter n value:");
        scanf("%d",&n);
    
        arr=generate_arr(n);
        printarr(arr,n);
        
        printf("\nEnter number to search:");
        scanf("%d",&key);
        index=l_search(arr,n,key);
        
        if(index!=-1)
            printf("\nnumber %d found at  index %d\n",key,index);
        else
           printf("\nnumber not found\n");
    
        free(arr);
        
    
    return 0;
}
