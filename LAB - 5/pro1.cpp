#include<stdio.h>

struct emp{
	int id;
	char name[20];
	char Designation[20];
	float salary;
};

int main(){	
	emp e1;
		
	printf("Enter Employee Id : ");
	scanf("%d",&e1.id);
	printf("Enter Employee  Name : ");
	scanf("%s",e1.name);
	printf("Enter Employee  Designation : ");
	scanf("%s",e1.Designation);
	printf("Enter Employee  Salary : ");
	scanf("%f",&e1.salary);
	
	
	printf("Id || Name || Designation || Salary\n");
	printf("%d  || %s || %s || %.2f\n",e1.id,e1.name,e1.Designation,e1.salary);


	return 0;

}
