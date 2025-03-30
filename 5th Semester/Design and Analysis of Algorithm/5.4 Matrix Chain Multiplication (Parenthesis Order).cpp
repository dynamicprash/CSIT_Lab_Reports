#include <stdio.h>
#include <limits.h>

void matrixChainOrder(int p[], int n) {
    int m[n][n], bracket[n][n], count = 0;

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                count++; // Increment iteration count
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    printf("\nPrashant Paudel\n");
    printf("Input Matrix Dimensions: ");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    
    printf("\nMinimum cost: %d\n", m[1][n - 1]);
    printf("Total iterations: %d\n", count);
}

int main() {
    int n;
    
    printf("--------Matrix Chain Multiplication--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    char repeat;
    do {
        printf("Enter number of matrices: ");
        scanf("%d", &n);
        
        int arr[n + 1];
        
        printf("Enter matrix dimensions: ");
        for (int i = 0; i <= n; i++)
            scanf("%d", &arr[i]);

        matrixChainOrder(arr, n + 1);

        printf("Do you want to run the algorithm again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
