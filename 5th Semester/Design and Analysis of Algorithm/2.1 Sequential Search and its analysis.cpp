#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform sequential search and count iterations
int sequentialSearch(int arr[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == target) {
            printf("Total iterations: %d\n", count);
            return i; // Return the index if the target is found
        }
    }
    printf("Total iterations: %d\n", count);
    return -1; // Return -1 if the target is not found
}

// Function to generate a random number within a range
int generateRandom(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    char choice;

    printf("--------SEQUENTIAL SEARCH--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    srand(time(0));

    do {
        printf("Do you want to enter the target manually or generate randomly? (m/r): ");
        scanf(" %c", &choice);

        if (choice == 'm' || choice == 'M') {
            printf("Enter the element to search: ");
            scanf("%d", &target);
        } else {
            target = generateRandom(10, 60); // Random target between 10 and 60
            printf("Generated target: %d\n", target);
        }

        // Perform sequential search
        int result = sequentialSearch(arr, n, target);

        // Display the result
        if (result != -1) {
            printf("Element found at index %d\n", result);
        } else {
            printf("Element not found in the array\n");
        }

        printf("Do you want to search for another element? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
