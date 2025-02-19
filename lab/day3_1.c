#include <stdio.h>

#define M 3 // Number of subjects (you can modify this as needed)

// Function prototypes
void calculateTotalMarks(int marks[][M], int n, int totalMarks[]);
void sortStudents(int totalMarks[], int marks[][M], int n);

int main() {
    int n, i, j;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    int marks[n][M];
    int totalMarks[n];
    
    // Read marks
    printf("Enter marks:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        for (j = 0; j < M; j++) {
            scanf("%d", &marks[i][j]);
        }
    }
    
    // Calculate total marks for each student
    calculateTotalMarks(marks, n, totalMarks);
    
    // Sort students in descending order of total marks
    sortStudents(totalMarks, marks, n);
    
    // Display sorted total marks
    printf("Sorted total marks:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: Total Marks = %d\n", i + 1, totalMarks[i]);
    }
    
    return 0;
}

// Function to calculate total marks for each student
void calculateTotalMarks(int marks[][M], int n, int totalMarks[]) {
    for (int i = 0; i < n; i++) {
        totalMarks[i] = 0;
        for (int j = 0; j < M; j++) {
            totalMarks[i] += marks[i][j];
        }
    }
}

// Function to sort students in descending order of total marks
void sortStudents(int totalMarks[], int marks[][M], int n) {
    int temp, tempMarks[M];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (totalMarks[i] < totalMarks[j]) {
                // Swap total marks
                temp = totalMarks[i];
                totalMarks[i] = totalMarks[j];
                totalMarks[j] = temp;
                
                // Swap marks array
                for (int k = 0; k < M; k++) {
                    tempMarks[k] = marks[i][k];
                    marks[i][k] = marks[j][k];
                    marks[j][k] = tempMarks[k];
                }
            }
        }
    }
}
