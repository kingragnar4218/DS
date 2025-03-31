#include <stdio.h>


struct Employee_Detail {
    int Employee_id;
    char Name[50];
    char Designation[50];
    float Salary;
};

int main() {

    struct Employee_Detail emp;


    printf("Enter Employee ID: ");
    scanf("%d", &emp.Employee_id);

    printf("Enter Employee Name: ");
    getchar(); 
    fgets(emp.Name, sizeof(emp.Name), stdin);

    printf("Enter Employee Designation: ");
    fgets(emp.Designation, sizeof(emp.Designation), stdin);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.Salary);

    
    printf("\nEmployee Details:\n");
    printf("Employee ID: %d\n", emp.Employee_id);
    printf("Name: %s", emp.Name);
    printf("Designation: %s", emp.Designation);
    printf("Salary: %.2f\n", emp.Salary);

    return 0;
}
