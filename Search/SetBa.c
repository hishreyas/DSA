/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A ,
a)Read the data from file 'cities.txt' containing names of cities and their STD codes. Accept a 
name of the city from user and use linear search algorithm to check whether the name is 
present in the file and output the STD code, otherwise output “city not in the list”.
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
  fp = fopen ("cities.txt","r");

  if(fp != NULL)
  {
        while(fscanf(fp,"%s%d",cities[i].name,&cities[i].std) != EOF) //read data and store in arraye
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

int  l_search(City *cities,int size,char *key)
{
     int i ;
     for(i=0;i<size;i++)
     {
         if(!strcmp(key,cities[i].name))
          return i;
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

       while(1)
      {
           printf("\nEnter city to search:");
           gets(key);
           index=l_search(cities,size,key);
           if(index!=-1)
               printf("\nCity name: %s | std code:%d\n",cities[index].name,cities[index].std);
           else
               printf("\n %s not in list\n",key);
      }

      }
        else
                printf("File not found in the directory");


}
