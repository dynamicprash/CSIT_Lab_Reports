#include<stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap elements without using pointers
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Heapify function to maintain max heap property
void heapify(int arr[], int n, int i, int* count) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) 
        largest = l;
    if (r < n && arr[r] > arr[largest]) 
        largest = r;

    if (largest != i) {
        swap(arr, i, largest);
        (*count)++;  // Increment iteration count
        heapify(arr, n, largest, count);
    }
}

// Heap Sort function
void heapSort(int arr[], int n, int* count) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i, count);
    
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i); // Move max element to end
        (*count)++;  // Increment iteration count for swap
        heapify(arr, i, 0, count); // Heapify reduced heap
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

    printf("HEAP SORT\n");
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
        heapSort(arr, n, &count);

        printf("Sorted array: ");
        printArray(arr, n);

        printf("Total iterations: %d\n", count);

        printf("Do you want to sort another array? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
