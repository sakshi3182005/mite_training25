#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int number;
    
    // Input from the user
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Check for negative input
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate factorial
         result = factorial(number);
        // Output the result
        printf("Factorial of %d is %d\n", number, result);
    }

    return 0;
}
