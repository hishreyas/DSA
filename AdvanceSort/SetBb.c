/*
Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
b)Using File handling sort by name.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define RANGE 255
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

void writeFile(Employee *emp,int size)
{
	int i;
	FILE *fp;
	fp = fopen("sortedemponname.txt","w+");
	if(fp!= NULL)
	{
		for (i = 0; i < size; i++)
			fprintf(fp, "%s\t%d\t%d\n", emp[i].name, emp[i].age, emp[i].salary);
			
		printf("\nrecords saved succesfull in sortedemponname.txt\n");
		fclose(fp);
	}
}
void swap(Employee *emp,int i,int j)
{
        Employee temp=emp[i];
        emp[i]=emp[j];
        emp[j]=temp;
}


void print_emp(Employee *emp,int size)
{
	int i;
	printf("\nEmployees Details:\n");
	for(i=0;i<size;i++)
	printf("\nname: %s || age: %d || salary: %d\n",emp[i].name,emp[i].age,emp[i].salary);
  
}

//return length of string which have maximum length
int get_max(Employee *emp,int size)
{
	int max=0,i;

	for(i=1;i<size;i++)
	{
		if(strlen(emp[max].name)<strlen(emp[i].name))
			max=i;
	}
	return strlen(emp[max].name);
}

//counting sort on character of string
int c_sort(Employee *emp,int size,int c)
{
	int count[RANGE+1];
	Employee output[size];
	int i;

	for(i=0;i<RANGE+1;i++)
		count[i]=0;

	for(i=0;i<size;i++)
			count[emp[i].name[c]]++;

	for(i=1;i<RANGE+1;i++)
		count[i]+=count[i-1];

	for(i=0;i<size;i++)
	{
		
			output[count[emp[i].name[c]]-1]=emp[i];
			count[emp[i].name[c]]--;
	}
	for(i=0;i<size;i++)
		emp[i]=output[i];
		
	return -1;
}

//radix sort uses counting sort for strings
Employee* r_sort(Employee *emp,int size)
{
	int i, max=get_max(emp,size);
	
	for(i=max-1;i>=0;i--)
		c_sort(emp,size,i);

	return emp;
}

void merge(Employee *emp,int low,int high,int mid)
{
	int i=low,j=mid+1,k=0;
	Employee b[30];
	
	while(i<=mid && j<=high)
	{
		if(strcmp(emp[i].name,emp[j].name)<=0)
			b[k++]=emp[i++];
		else
			b[k++]=emp[j++];
	}

	while(i<=mid)
		b[k++]=emp[i++];

	while(j<=high)
		b[k++]=emp[j++];

	for(j=low,k=0;j<=high;j++,k++)
		emp[j]=b[k];
}
Employee* m_sort(Employee *emp,int low,int high)
{
	int mid=(low+high-1)/2;

	if(low<high)
	{
		m_sort(emp,low,mid);
		m_sort(emp,mid+1,high);
		merge(emp,low,high,mid);
	}
	return emp;
}
int partition(Employee *emp,int lb,int ub)
{
	int down=lb+1,up=ub;
	Employee pivot=emp[lb];

	do
	{
		while(strcmp(emp[down].name,pivot.name)<0 && down<=up)
			down++;

		while(strcmp(emp[up].name,pivot.name)>0 && up>=down)
			up--;

		if(down<up)
		{
		  Employee temp=emp[down];
		  emp[down]=emp[up];
		  emp[up]=temp;
		}
	}while(down<up);
	emp[lb]=emp[up];
	emp[up]=pivot;

	return up;
}

Employee* q_sort(Employee *emp,int lb,int ub)
{
	int j;
	
	if(lb<ub)
	{
		j=partition(emp,lb,ub);
		q_sort(emp,lb,j-1);
		q_sort(emp,j+1,ub);
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
			puts("1-COUNTING(using RADIX) SORT");
			puts("2-MERGE SORT");
			puts("3-QUICK SORT");
			printf("\nEnter choice:");
			scanf("%d",&choice);
      puts("---------------------------order by name--------------------------");
			switch(choice)
			{
			  
			  case 1:
			  print_emp(r_sort(emp,size),size);
			  break;
			  
				case 2:
			  print_emp(m_sort(emp,0,size-1),size);
				break;
				
				case 3:
				print_emp(q_sort(emp,0,size-1),size);
			  break;
			  
				default:
				puts("Enter valid choice please");
				break;
			}
			writeFile(emp,size);
		}
		else
			printf("File not found");
	}
}
