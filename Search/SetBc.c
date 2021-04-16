/*                                                                
Name:Shreyas Prabhakar Bansode 
Roll no:6 
Problem: Set B ,
c)
Read the data from file ‘sortedcities.txt’ containing sorted names of cities and their STD codes. Accept a name of the city from user and use binary search algorithm to check whetherthe name is present in the file and output the STD code, otherwise output “city not in the list”.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cities
{
  char name[30];
  int std;

}City;

int store(City *cities)
{
    int i = 0;
    FILE *fp;
    fp = fopen ("sortedcities.txt","r");

   if(fp != NULL)
   {
      while(fscanf(fp,"%s%d",cities[i].name,&cities[i].std) != EOF) //read data and store in array
      i++;
         
      fclose(fp);
      return i;    //returns size of array
    }
    else
      return -1;

}
void display(City *cities,int size)
{
        int i;
        puts("Cities details");
        for(i=0;i<size;i++)
                printf("\nCity name: %s || std code:%d",cities[i].name,cities[i].std);
}


int search(City *cities,int l,int r,char *key)
{
    int mid;                                                      
    while(l<=r)
    {                                                          
	    mid=(l+r)/2;
      if( !strcmp(cities[mid].name,key))                 
		    return mid;
                                                                                      
	    if(strcmp(key,cities[mid].name)>0)
		    l=mid+1;                                                              
	    else                                                   
		    r=mid-1;                                                    


    }
    return -1;
}

int main ()
{
     char key[30];
     City cities[50];
     int index;
     int size;

     size=store(cities);     
     
     if(size!=-1) // i.e if file exits
     {
       display(cities,size);
       while (1)
      {
          printf("\nEnter city to search:");
          gets(key);

          index=search(cities,0,size-1,key);

          if(index!=-1)
              printf("\nCity name: %s | std code:%d\n",cities[index].name,cities[index].std);
          else
              printf("\n %s not in list the list\n",key);
      }
       
     }
     else
        printf("File not found in the directory");


}
