#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int marks;
} Student;

int main() {
    int numStudents;

    // Input the number of students
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for student records
    Student *students = (Student *)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Input student details
    for (int i = 0; i < numStudents; i++) {
        students[i].name = (char *)malloc(50 * sizeof(char)); // Allocate memory for name
        if (students[i].name == NULL) {
            printf("Memory allocation for name failed!\n");
            return 1; // Exit if memory allocation fails
        }

        printf("Enter Student %d Name: ", i + 1);
        scanf("%s", students[i].name); // Input student name
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks); // Input student marks
    }

    // Output student records
    printf("\nStudent Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    // Free allocated memory
    for (int i = 0; i < numStudents; i++) {
        free(students[i].name); // Free memory allocated for each name
    }
    free(students); // Free memory allocated for student records

    return 0;
}
