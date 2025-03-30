#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int l, int h, int* count) {
    int pivot = arr[h];
    int i = (l - 1);
    for (int j = l; j < h; j++) {
        (*count)++; // Increment iteration count
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, h);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int l, int h, int* count) {
    if (l < h) {
        int pi = partition(arr, l, h, count);
        quickSort(arr, l, pi - 1, count);
        quickSort(arr, pi + 1, h, count);
    }
}

// Function to generate random number within a range
int generateRandom(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10], n, choice;
    char repeat;
    int count;

    printf("--------QUICK SORT--------\n");
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

        count = 0;  // Reset iteration count
        quickSort(arr, 0, n - 1, &count);

        printf("Sorted array: ");
        printArray(arr, n);

        printf("Total iterations: %d\n", count);

        printf("Do you want to sort another array? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
