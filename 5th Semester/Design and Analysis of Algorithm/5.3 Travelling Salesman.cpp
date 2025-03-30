#include <stdio.h>
#include <limits.h>

#define INF 99999
#define N 4

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[N][N], int mask, int pos, int dp[N][1 << N], int* count) {
    if (mask == (1 << N) - 1)
        return graph[pos][0];

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int res = INF;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            (*count)++; // Increment iteration count
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp, count);
            res = min(res, newAns);
        }
    }

    return dp[pos][mask] = res;
}

int main() {
    int graph[N][N], count;

    printf("--------Traveling Salesman Problem (TSP)--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    char repeat;
    do {
        printf("Enter cost matrix for %d cities:\n", N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &graph[i][j]);

        int dp[N][1 << N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < (1 << N); j++)
                dp[i][j] = -1;

        count = 0;  // Reset iteration count
        printf("\nPrashant Paudel\n");
        printf("Input Cost Matrix:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%d ", graph[i][j]);
            printf("\n");
        }

        printf("\nMinimum cost of TSP: %d\n", tsp(graph, 1, 0, dp, &count));
        printf("Total iterations: %d\n", count);

        printf("Do you want to run the algorithm again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
