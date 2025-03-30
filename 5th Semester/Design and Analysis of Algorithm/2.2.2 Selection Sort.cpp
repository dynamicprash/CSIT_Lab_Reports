#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap elements without pointers
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Iterative Selection Sort function with iteration count tracking
void selectionSort(int arr[], int n) {
    int totalIterations = 0; // Track total iterations

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  

        // Find the minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            totalIterations++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(arr, i, minIndex);
        }
    }

    printf("Total iterations: %d\n", totalIterations);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate a random number within a range
int generateRandom(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    int arr[10], n, choice;
    char repeat;

    printf("--------SELECTION SORT--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    srand(time(0));

    do {
        printf("Enter the number of elements (max 10): ");
        scanf("%d", &n);

        printf("Choose input method: (1) Manual (2) Random: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter %d elements:\n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
        } else {
            printf("Generated array: ");
            for (int i = 0; i < n; i++) {
                arr[i] = generateRandom(1, 100);
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        printf("Original array: ");
        printArray(arr, n);

        selectionSort(arr, n);

        printf("Sorted array: ");
        printArray(arr, n);

        printf("Do you want to sort another array? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
