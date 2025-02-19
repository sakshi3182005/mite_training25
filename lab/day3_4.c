#include <stdio.h>

// Function prototype
int mostFrequentElement(int arr[], int n);

int main() {
    int n, i;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = mostFrequentElement(arr, n);
    printf("Most Frequent Element: %d\n", result);
    
    return 0;
}

// Function to find the most frequent element in an array
int mostFrequentElement(int arr[], int n) {
    int maxCount = 0, result = arr[0];
    int i, j;
    
    for (i = 0; i < n; i++) {
        int count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        if (count > maxCount || (count == maxCount && arr[i] < result)) {
            maxCount = count;
            result = arr[i];
        }
    }
    
    return result;
}
