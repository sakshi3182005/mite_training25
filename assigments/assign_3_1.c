#include <stdio.h>
#include <string.h>

// Define a structure to store passenger details
struct Passenger {
    char name[100];
    int age;
    char destination[100];
};

// Function to add a new passenger
void addPassenger(struct Passenger passengers[], int *count) {
    printf("Enter passenger %d details (Name, Age, Destination): ", *count + 1);
    scanf("%s %d %s", passengers[*count].name, &passengers[*count].age, passengers[*count].destination);
    (*count)++;
}

// Function to sort passengers by destination name (A-Z)
void sortPassengersByDestination(struct Passenger passengers[], int count) {
    struct Passenger temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(passengers[i].destination, passengers[j].destination) > 0) {
                temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }
}

// Function to search for passengers traveling to a specific destination
void searchPassengersByDestination(struct Passenger passengers[], int count, char destination[]) {
    printf("Passengers traveling to %s:\n", destination);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].destination, destination) == 0) {
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers traveling to %s.\n", destination);
    }
}

int main() {
    int N;
    printf("Enter number of passengers: ");
    scanf("%d", &N);

    struct Passenger passengers[N];
    int count = 0;

    // Add passengers
    for (int i = 0; i < N; i++) {
        addPassenger(passengers, &count);
    }

    // Sort passengers by destination
    sortPassengersByDestination(passengers, count);

    // Display sorted list
    printf("Sorted List (by destination):\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", passengers[i].name, passengers[i].destination);
    }

    // Search for passengers traveling to a specific destination
    char destination[100];
    printf("Enter destination to search: ");
    scanf("%s", destination);
    searchPassengersByDestination(passengers, count, destination);

    return 0;
}
