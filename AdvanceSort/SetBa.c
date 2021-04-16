/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
a)Using File handling sort by age.
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

void writeFile(Employee *emp,int size)
{
	int i;
	FILE *fp;
	fp = fopen("sortedemponage.txt","w+");
	if(fp!= NULL)
	{
		for (i = 0; i < size; i++)
			fprintf(fp, "%s\t%d\t%d\n", emp[i].name, emp[i].age, emp[i].salary);
			
		printf("\nrecords saved succesfull in sortedemponage.txt\n");
		fclose(fp);
	}
}

void print_emp(Employee *emp,int size)
{
	int i;
	printf("\nEmployees Details:\n");
	for(i=0;i<size;i++)
	printf("\nname: %s || age: %d || salary: %d\n",emp[i].name,emp[i].age,emp[i].salary);
  
}


Employee * c_sort(Employee *emp,int size,int range)
{
	int count[range+1];
	Employee output[size];
	int i;

	for(i=0;i<range+1;i++)
		count[i]=0;

	for(i=0;i<size;i++)
		count[emp[i].age]++;

	for(i=1;i<range+1;i++)
		count[i]+=count[i-1];

	for(i=size-1;i>=0;i--)
	{
		output[count[emp[i].age]-1]=emp[i];
			count[emp[i].age]--;
	}
	for(i=0;i<size;i++)
		emp[i]=output[i];

	return emp;
}

void merge(Employee *emp,int low,int high,int mid)
{
	int i=low,j=mid+1,k=0;
	Employee b[30];

	while(i<=mid && j<=high)
	{
		if(emp[i].age<=emp[j].age)
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
Employee *m_sort(Employee *emp,int low,int high)
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
		while(emp[down].age<pivot.age && down<=up)
			down++;

		while(emp[up].age>pivot.age && up>=down)
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

Employee * q_sort(Employee *emp,int lb,int ub)
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
			puts("1-COUNTING SORT");
			puts("2-MERGE SORT");
			puts("3-QUICK SORT");
			printf("\nEnter choice:");
			scanf("%d",&choice);
      puts("---------------------------order by age--------------------------");
			switch(choice)
			{
			  
			  case 1:
			  print_emp(c_sort(emp,size,50),size);
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
