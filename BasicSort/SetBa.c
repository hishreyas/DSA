/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
a) Read the data from the file “employee.txt” and sort on age using bubble sort, insertion sort 
and selection sort.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee
{
	char name[30];
	int age;
	int salary;
}Employee;


int store(Employee *emp)
{
	int i=0;
	FILE *fp;
	
	fp=fopen("Employee.txt","r");

	if(fp!=NULL)
	{
		while(fscanf(fp,"%s %d %d",emp[i].name,&emp[i].age,&emp[i].salary)!=EOF)
		i++;
		
		fclose(fp);
		return i;
	}
		return -1;
}

void print_emp(Employee *emp,int size)
{
	int i;
	printf("\nEmployees Details:\n");
  for(i=0;i<size;i++)
	printf("\nname: %s || age: %d || salary: %d\n",emp[i].name,emp[i].age,emp[i].salary);
}

void swap(Employee *emp,int i,int j)
{
    Employee temp=emp[i];
    emp[i]=emp[j];
    emp[j]=temp;
}

Employee * b_sort(Employee *emp,int size)
{
	int i,j;

	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(emp[j].age>emp[j+1].age)
				swap(emp,j,j+1);
		}
	}
	return emp;
}

Employee * i_sort(Employee *emp,int size)
{
  int i,j;
	Employee temp;
	
  for(i=1;i<size;i++)
  {
    temp=emp[i];
    for(j=i-1;(temp.age<emp[j].age && j>=0);j--)
      emp[j+1]=emp[j];

		emp[j+1]=temp;
  }

  return emp;
}

Employee * s_sort(Employee *emp,int size)
{
  int i,j,min;

  for(i=0;i<size-1;i++)
  {
    min=i;
    for(j=i+1;j<size;j++)
    {
      if(emp[j].age<emp[i].age)
      min=j;
    }
   swap(emp,i,min);
  }
  return emp;
}
int main()
{
	
	int choice,size;
	Employee emp[40];

	while(1)
	{
	  size=store(emp);
	  if(size!=-1)
		{
		  puts("-----------------------------------------------------");
		  print_emp(emp,size);
			puts("1-BUBBLE SORT");
			puts("2-ISERTION SORT");
			puts("3-SELECTION SORT");
			printf("\nEnter choice:");
			scanf("%d",&choice);
      puts("---------------------------order by age--------------------------");
			switch(choice)
			{
			  
			  case 1:
			  print_emp(b_sort(emp,size),size);
			  break;
			  
				case 2:
			  print_emp(i_sort(emp,size),size);
				break;
				
				case 3:
				print_emp(s_sort(emp,size),size);
			  break;
			  
				default:
				puts("Enter valid choice please");
				break;
			}
		}
		else
			printf("File not found");
	}
}
