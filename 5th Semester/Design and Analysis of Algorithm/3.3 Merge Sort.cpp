#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two halves
void merge(int arr[], int l, int m, int r, int* count) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        (*count)++;  // Increment iteration count
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
        (*count)++;
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
        (*count)++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int l, int r, int* count) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}

// Function to generate random number within a range
int generateRandom(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[10], n, choice, count;
    char repeat;

    printf("--------MERGE SORT--------\n");
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
        mergeSort(arr, 0, n - 1, &count);

        printf("Sorted array: ");
        printArray(arr, n);

        printf("Total iterations: %d\n", count);

        printf("Do you want to sort another array? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
