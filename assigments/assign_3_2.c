#include <stdio.h>
#include <string.h>

// Function to find and count occurrences of a pattern in a DNA sequence
int countPatternOccurrences(char dna[], char pattern[]) {
    int count = 0;
    char *ptr = dna;

    while ((ptr = strstr(ptr, pattern)) != NULL) {
        count++;
        ptr++;
    }

    return count;
}

int main() {
    char dna[1000];
    char pattern[100];

    // Input DNA sequence
    printf("Enter DNA Sequence: ");
    scanf("%s", dna);

    // Input pattern to search
    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    // Count occurrences of the pattern
    int occurrences = countPatternOccurrences(dna, pattern);

    // Output the result
    printf("Pattern found %d time(s) in the DNA sequence.\n", occurrences);

    return 0;
}
