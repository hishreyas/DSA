/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
a)Sort a random array of n integers (accept the value of n from user) in ascending order by 
using bubble sort algorithm.
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
    for( i=0;i<n;i++)
        printf(" %d ",arr[i]);
        
    printf("\n");
}

int *b_sort(int *arr,int n)
{
	int i,j,temp;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	return arr;
}

int main()
{
    int *arr;
    int n;

    srand(time(0));


    printf("\nEnter n value:");
    scanf("%d",&n);
    arr=generate_arr(n);
    printarr(arr,n);

	  printf("\nSorted array using bubble sort\n");
	  printarr(b_sort(arr,n),n);
    free(arr);
    return 0;
}
