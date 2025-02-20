#include <stdio.h>

// Define the structure for Employee
struct Employee_t {
    int id;
    char name[255];
    float salary;
    char department[50];
};

typedef struct Employee_t Employee;

// Function prototypes
void readEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);

int main() {
    int employeeCount;
    printf("Enter number of employees: ");
    scanf("%d", &employeeCount);

    Employee employees[1000];
    readEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);

    Employee HighestSalariedEmployee = findHighestSalary(employees, employeeCount);
    printf("Employee with highest salary: %s, %.2f (%s)\n",
           HighestSalariedEmployee.name,
           HighestSalariedEmployee.salary,
           HighestSalariedEmployee.department);

    return 0;
}

void readEmployees(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Employee [%d] name: ", i + 1);
        scanf("%s", emp[i].name);
        printf("Employee [%d] ID: ", i + 1);
        scanf("%d", &emp[i].id);
        printf("Employee [%d] salary: ", i + 1);
        scanf("%f", &emp[i].salary);
        printf("Employee [%d] department: ", i + 1);
        scanf("%s", emp[i].department);
    }
}

void displayEmployees(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Employee [%d]: %s, %d, %.2f, %s\n",
               i + 1,
               emp[i].name,
               emp[i].id,
               emp[i].salary,
               emp[i].department);
    }
}

Employee findHighestSalary(Employee emp[], int n) {
    Employee highest = emp[0];
    for (int i = 1; i < n; i++) {
        if (emp[i].salary > highest.salary) {
            highest = emp[i];
        }
    }
    return highest;
}
