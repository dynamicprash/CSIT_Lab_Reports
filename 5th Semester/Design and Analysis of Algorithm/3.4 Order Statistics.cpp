#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = (l - 1);
    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

// Order Statistics (K-th Smallest Element)
int kthSmallest(int arr[], int l, int r, int k, int* count) {
    (*count)++; // Increment iteration count for each call
    if (l <= r) {
        int pi = partition(arr, l, r);
        if (pi - l == k - 1) return arr[pi];
        if (pi - l > k - 1) return kthSmallest(arr, l, pi - 1, k, count);
        return kthSmallest(arr, pi + 1, r, k - pi + l - 1, count);
    }
    return -1;
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
    int k = 3, n, choice, count;
    char repeat;

    printf("--------K-th Smallest Element--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    srand(time(0));

    do {
        printf("Enter the number of elements (max 10): ");
        scanf("%d", &n);

        printf("Choose input method: (1) Manual (2) Random: ");
        scanf("%d", &choice);

        int arr[n];

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
        int kth = kthSmallest(arr, 0, n - 1, k, &count);

        if (kth != -1)
            printf("%dth smallest element is %d\n", k, kth);
        else
            printf("Element not found.\n");

        printf("Total iterations: %d\n", count);

        printf("Do you want to find another element? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
