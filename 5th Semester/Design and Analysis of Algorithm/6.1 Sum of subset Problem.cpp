#include <stdio.h>

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

void subsetSum(int arr[], int subset[], int n, int index, int sum, int target, int subsetSize) {
    if (sum == target) {
        printSubset(subset, subsetSize);
        return;
    }
    if (index == n || sum > target)
        return;

    subset[subsetSize] = arr[index];  
    subsetSum(arr, subset, n, index + 1, sum + arr[index], target, subsetSize + 1);

    subsetSum(arr, subset, n, index + 1, sum, target, subsetSize);
}

int main() {
    int n, target;
    printf("Prashant Paudel\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], subset[n];
    printf("Enter the set elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subset solutions:\n");
    subsetSum(arr, subset, n, 0, 0, target, 0);
    
    return 0;
}
#include <stdio.h>

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

void subsetSum(int arr[], int subset[], int n, int index, int sum, int target, int subsetSize, int* iterationCount) {
    (*iterationCount)++;  // Increment the iteration count each time the function is called
    
    if (sum == target) {
        printSubset(subset, subsetSize);
        return;
    }
    if (index == n || sum > target)
        return;

    subset[subsetSize] = arr[index];
    subsetSum(arr, subset, n, index + 1, sum + arr[index], target, subsetSize + 1, iterationCount);

    subsetSum(arr, subset, n, index + 1, sum, target, subsetSize, iterationCount);
}

int main() {
    int n, target, iterationCount;
    char repeat;

    printf("--------Subset Sum Problem--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    do {
        printf("Enter the number of elements: ");
        scanf("%d", &n);

        int arr[n], subset[n];
        printf("Enter the set elements: ");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("Enter the target sum: ");
        scanf("%d", &target);

        iterationCount = 0;  // Reset iteration count for each run
        printf("Subset solutions:\n");
        subsetSum(arr, subset, n, 0, 0, target, 0, &iterationCount);

        printf("Total iterations: %d\n", iterationCount);

        printf("Do you want to run the algorithm again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
