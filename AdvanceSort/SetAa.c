
/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
a) counting sort
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


void print_arr(int *arr,int n)
{
    printf("\n");
    int i;
    for( i=0;i<n;i++)
        printf(" %d ",arr[i]);
    printf("\n");
}
int *c_sort(int *arr,int range,int n)
{
    int output[n];
    int count[range+1];
    int i;
    
   
    for(i=0;i<range+1;i++)
       count[i]=0;
    
    for(i=0;i<n;i++)
     ++count[arr[i]];
    
    for(i=1;i<=range;i++)
      count[i]+=count[i-1];
    
    for(i=n-1;i>=0;i--)
    {
        output[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    
    for(i=0;i<n;i++)
    arr[i]=output[i];
    
    return arr;
}
int main()
{
    int *arr;
    int range,n;
    
    printf("\n Enter range:");
    scanf("%d",&range);
    printf("\nEnter n value:");
    scanf("%d",&n);
    arr=generate_arr(n,range);
    print_arr(arr,n);
    printf("\nSorted array using counting sort :");
    print_arr(c_sort(arr,range,n),n);
    free(arr);
}
