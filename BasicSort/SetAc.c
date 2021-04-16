/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
c)Sort a random array of n integers (accept the value of n from user) in ascending order by
using selection sort algorithm.
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

int *s_sort(int *arr,int n)
{
        int i,j,min,temp;

        for(i=0;i<n-1;i++)
        {
          min=i;
          
          for(j=i+1;j<n;j++)
          {
            if(arr[min]>arr[j])
              min=j;
             
          }
          temp=arr[i];
          arr[i]=arr[min];
         arr[min]=temp;
          
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

        printf("\nSorted array using selection sort\n");

        printarr(s_sort(arr,n),n);
        free(arr);


    return 0;
}
