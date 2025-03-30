#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nPrashant Paudel\n");
    printf("Input Values: \n");
    printf("Weights: ");
    for (int i = 0; i < n; i++) printf("%d ", wt[i]);
    printf("\nValues: ");
    for (int i = 0; i < n; i++) printf("%d ", val[i]);
    printf("\nKnapsack Capacity: %d\n", W);
    
    printf("\nMaximum Value: %d\n", dp[n][W]);
}

int main() {
    int n, W;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int val[n], wt[n];
    
    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    
    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(W, wt, val, n);
    return 0;
}
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n, int* count) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            (*count)++; // Increment iteration count for each inner loop execution
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Display Results
    printf("\nPrashant Paudel\n");
    printf("Input Values: \n");
    printf("Weights: ");
    for (int i = 0; i < n; i++) printf("%d ", wt[i]);
    printf("\nValues: ");
    for (int i = 0; i < n; i++) printf("%d ", val[i]);
    printf("\nKnapsack Capacity: %d\n", W);
    
    printf("\nMaximum Value: %d\n", dp[n][W]);
}

int main() {
    int n, W, count;
    
    printf("--------Knapsack Problem--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    char repeat;
    do {
        printf("Enter the number of items: ");
        scanf("%d", &n);
        
        int val[n], wt[n];
        
        printf("Enter values of items: ");
        for (int i = 0; i < n; i++) scanf("%d", &val[i]);
        
        printf("Enter weights of items: ");
        for (int i = 0; i < n; i++) scanf("%d", &wt[i]);
        
        printf("Enter knapsack capacity: ");
        scanf("%d", &W);

        count = 0;  // Reset iteration count
        knapsack(W, wt, val, n, &count);

        printf("Total iterations: %d\n", count);

        printf("Do you want to run the algorithm again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
