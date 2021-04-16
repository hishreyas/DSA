/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
c)Quick sort
*/
#include<stdio.h>
#include<stdlib.h>


int * generate_arr(int n,int range)
{
    int i;
    int * arr=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
        arr[i]=rand()%range;

    return arr;
}


void printarr(int *arr,int n)
{
    printf("\n");
    int i;
    for( i=0;i<n;i++)
        printf(" %d ",arr[i]);
    printf("\n");
    
}

int partition(int *arr,int lb,int ub)
{
    int down=lb+1,up=ub,temp;
    int pivot=arr[lb];
    
    do
    {
        while((arr[down]<pivot )&& down<=up)
          down++;
        while(arr[up]>pivot&& up>=down)
          up--;
        
        if(down<up)
        {
            temp=arr[up];
            arr[up]=arr[down];
            arr[down]=temp;
        }
        
     }while(down<up);
    
    
     arr[lb]=arr[up];
     arr[up]=pivot;
    
   
    return up;
    
}

int*  q_sort(int *arr,int lb,int ub,int n)
{
    int j;
    if(lb<ub)
    {
        j=partition(arr,lb,ub);
        q_sort(arr,lb,j-1,n);
        q_sort(arr,j+1,ub,n);
        
    }
    return arr;
}

int main()
{
    int *arr;
    int n;
    
    printf("\nEnter n value:");
    scanf("%d",&n);
    arr=generate_arr(n,100);
    printarr(arr,n);
    printf("\nSorted array using quicksort:");
    printarr(q_sort(arr,0,n-1,n),n);
    free(arr);
}
