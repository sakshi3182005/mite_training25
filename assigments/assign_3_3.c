#include <stdio.h>

// Function to find the highest score
int findHighestScore(int scores[], int size) {
    int highest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

// Function to find the lowest score
int findLowestScore(int scores[], int size) {
    int lowest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}

// Function to calculate the average score
float calculateAverageScore(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return (float)sum / size;
}

int main() {
    int scores[100];
    int n;

    // Input the number of scores
    printf("Enter the number of matches: ");
    scanf("%d", &n);

    // Input the scores
    printf("Enter scores of %d matches: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    // Find the highest score
    int highest = findHighestScore(scores, n);

    // Find the lowest score
    int lowest = findLowestScore(scores, n);

    // Calculate the average score
    float average = calculateAverageScore(scores, n);

    // Output the results
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.1f\n", average);

    return 0;
}
