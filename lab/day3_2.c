#include <stdio.h>
#include <string.h>

// Function prototype
void reverseWords(char str[]);

int main() {
    char str[100];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Reverse words in the sentence
    reverseWords(str);

    printf("Reversed Sentence: %s\n", str);

    return 0;
}

// Function to reverse a word
void reverseWord(char word[], int start, int end) {
    while (start < end) {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

// Function to reverse the words in a sentence
void reverseWords(char str[]) {
    int start = 0, end = 0, len = strlen(str);

    while (end <= len) {
        if (str[end] == ' ' || str[end] == '\0') {
            reverseWord(str, start, end - 1);
            start = end + 1;
        }
        end++;
    }
}
