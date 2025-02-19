#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototype
int isPalindrome(char str[]);

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int start = 0, end = strlen(str) - 1;

    while (start < end) {
        // Skip non-alphanumeric characters and convert to lowercase
        while (start < end && !isalnum(str[start])) {
            start++;
        }
        while (start < end && !isalnum(str[end])) {
            end--;
        }

        // Compare characters
        if (tolower(str[start]) != tolower(str[end])) {
            return 0; // Not a palindrome
        }

        start++;
        end--;
    }

    return 1; // Is a palindrome
}
