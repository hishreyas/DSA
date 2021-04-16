/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
b)Accept n values in array from user. Accept a value x from user and use sentinel linear 
search algorithm to check whether the number is present in the array or not and output the 
position if the number is present.
*/
#include<stdio.h>
#include<stdlib.h>

int * acceptarr(int n)
{
    int *arr=(int *)malloc(sizeof(int)*n);
    int i;
    
    printf("Enter n elements\n");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    
    return arr;
}

int s_search(int* arr,int n,int key)
{
    int i=0;
    
    int last=arr[n-1];
    
    arr[n-1]=key;
    
    while(arr[i]!=key)
     i++;
    
    arr[n-1]=last;
    
    if(arr[i]==key)
     return i;
    else
     return -1;
    
}

int main()
{
    int n,index,key;
    int *arr;
    
    
   
    printf("\nEnter n value:");
    scanf("%d",&n);
    
    arr=acceptarr(n);
    
    
    printf("\nEnter number to search:");
    scanf("%d",&key);
   
    
    index=s_search(arr,n,key);
    
    if(index!=-1)
        printf("\n%d found at index %d\n",key,index);
    else
        printf("\n%d not found\n",key);
    
    free(arr);
        
       
    
}
