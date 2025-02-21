#include <stdio.h>
#include <ctype.h> // For isspace()

void countWordsAndLines(char filename[]) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return; // Or exit(1); if you prefer to terminate on error
    }

    int lineCount = 0;
    int wordCount = 0;
    char ch;
    int inWord = 0; // Flag to track if we're inside a word

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }

        if (isspace(ch) || ch == '\n' || ch == '\t') {
            if (inWord) {
                wordCount++;
                inWord = 0; // We've just finished a word
            }
        } else {
            inWord = 1; // We're inside a word
        }
    }

    // Check for a word at the very end of the file (if no trailing whitespace)
    if (inWord) {
        wordCount++;
    }

    printf("Total Lines: %d\n", lineCount);
    printf("Total Words: %d\n", wordCount);

    fclose(fp);
}

int main() {
    char filename[100]; // Adjust size as needed

    printf("Enter filename: ");
    scanf("%99s", filename); // Limit input to prevent buffer overflows

    countWordsAndLines(filename);

    return 0;
}
