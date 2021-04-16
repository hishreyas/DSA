/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
b)Sort a random array of n integers (accept the value of n from user) in ascending order by
using insertion sort algorithm.
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

int *i_sort(int *arr,int n)
{
  int i,j,temp;

  for(i=1;i<n;i++)
  {
    temp=arr[i];

		for(j=i-1; (j>=0) && (temp<arr[j]);j--)
			arr[j+1]=arr[j];
			
		arr[j+1]=temp;
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

    printf("\nSorted array using insertion sort\n");

    printarr(i_sort(arr,n),n);
    free(arr);


    return 0;
}
