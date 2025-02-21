#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()

// Structure for Employee
typedef struct {
    int ID;
    char Name[50];
    float Salary;
} Employee;

// Function to write employee records to a file
void writeToFile(Employee emp[], int n) {
    FILE *fp = fopen("employees.txt", "w"); // Open file in write mode

    if (fp == NULL) {
        perror("Error opening file for writing"); // More informative error message
        exit(1); // Exit with an error code
    }

    fprintf(fp, "ID\tName\tSalary\n"); //Header for easy readability
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\t%s\t%.2f\n", emp[i].ID, emp[i].Name, emp[i].Salary); // Write formatted data
    }

    fclose(fp);
    printf("Employee data written to employees.txt\n");
}

// Function to read employee records from a file and display them
void readFromFile() {
    FILE *fp = fopen("employees.txt", "r"); // Open file in read mode

    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }

    printf("Employees Data from File:\n");
    char line[100]; // To read the line
    while (fgets(line, sizeof(line), fp) != NULL) { // Read line by line
        printf("%s", line); // Print the line
    }
   

    fclose(fp);
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character left by scanf

    Employee employees[n];

    printf("Enter details (ID, Name, Salary):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &employees[i].ID, employees[i].Name, &employees[i].Salary);
        getchar(); // Consume the newline after each employee input
    }

    writeToFile(employees, n);
    readFromFile();

    return 0;
}
