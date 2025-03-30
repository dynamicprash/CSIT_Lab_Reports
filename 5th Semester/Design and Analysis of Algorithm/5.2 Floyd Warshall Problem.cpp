#include <stdio.h>

#define INF 99999
#define V 4

void floydWarshall(int graph[V][V], int* count) {
    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                (*count)++; // Increment iteration count
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("\nPrashant Paudel\n");
    printf("Input Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%7d ", (graph[i][j] == INF) ? -1 : graph[i][j]);
        printf("\n");
    }

    printf("\nShortest distances:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%7d ", (dist[i][j] == INF) ? -1 : dist[i][j]);
        printf("\n");
    }
}

int main() {
    int graph[V][V], count;
    
    printf("--------Floyd-Warshall Algorithm--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    char repeat;
    do {
        printf("Enter adjacency matrix (use 99999 for INF):\n");
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                scanf("%d", &graph[i][j]);

        count = 0;  // Reset iteration count
        floydWarshall(graph, &count);

        printf("Total iterations: %d\n", count);

        printf("Do you want to run the algorithm again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
