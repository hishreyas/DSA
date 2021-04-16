
/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
b)Merge sort
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

void merge(int *arr,int low,int high,int mid)
{
    int i=low,j=mid+1,k=0;
    int b[30];
    
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
          b[k++]=arr[i++];
        else
          b[k++]=arr[j++];
    }
    
    while(i<=mid)
       b[k++]=arr[i++];
    
    while(j<=high)
      b[k++]=arr[j++];
    
    
    for(j=low,k=0;j<=high;j++,k++)
      arr[j]=b[k];
    
}

int *  m_sort(int *arr,int low,int high)
{
    int mid=(low+high-1)/2;
    
    if(low<high)
    {
        m_sort(arr,low,mid);
        m_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
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
    printf("\nSorted array using merge sort:");
    printarr(m_sort(arr,0,n-1),n);
    free(arr);

   
}
