
/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
c) Accept n sorted values in array from user. Accept a value x from user and use binary 
search algorithm to check whether the number is present in sorted array or not and output the 
position if the number is present.
*/
#include<stdio.h>
#include<stdlib.h>

int search(int *arr,int l,int r,int key)
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        
        if(arr[mid]==key)
         return mid;
        
        if(key>arr[mid])
         l=mid+1;
        else
         r=mid-1;
        
    }
    return -1;
}
int * acceptarr(int n)
{
    int *arr=(int *)malloc(sizeof(int)*n);
    int i;

    printf("Enter n elements\n");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
		
    return arr;
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
	index=search(arr,0,n-1,key);

	if(index!=-1)
		printf("\n%d found at index %d\n",key,index);
	else
		printf("\n%d not found\n",key);
    
    free(arr);
        
    
}
