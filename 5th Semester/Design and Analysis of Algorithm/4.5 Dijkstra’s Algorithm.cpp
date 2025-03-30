#include <stdio.h>
#include <limits.h>

#define V 5

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] < min)
                min = dist[v], u = v;

        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++) printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {{0, 10, 0, 0, 5}, {10, 0, 1, 0, 2}, {0, 1, 0, 4, 0}, {0, 0, 4, 0, 3}, {5, 2, 0, 3, 0}};
    dijkstra(graph, 0);
    return 0;
}
#include <stdio.h>

#define INF 999999 // Define your own large number as infinity

void dijkstra(int graph[5][5], int src, int* count) {
    int dist[5], visited[5] = {0};

    for (int i = 0; i < 5; i++) dist[i] = INF; // Use custom 'INF' value
    dist[src] = 0;

    for (int count_iter = 0; count_iter < 5 - 1; count_iter++) {
        (*count)++; // Increment iteration count for each outer loop execution
        int min = INF, u;
        for (int v = 0; v < 5; v++)
            if (!visited[v] && dist[v] < min)
                min = dist[v], u = v;

        visited[u] = 1;
        for (int v = 0; v < 5; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < 5; i++) printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int graph[5][5] = {{0, 10, 0, 0, 5}, {10, 0, 1, 0, 2}, {0, 1, 0, 4, 0}, {0, 0, 4, 0, 3}, {5, 2, 0, 3, 0}};
    int count;

    printf("--------Dijkstra Algorithm--------\n");
    printf("Developed by: Prashant Paudel\n\n");

    char repeat;
    do {
        count = 0;  // Reset iteration count
        dijkstra(graph, 0, &count);

        printf("Total iterations: %d\n", count);

        printf("Do you want to run the algorithm again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Exiting the program! - Prashant Paudel\n");

    return 0;
}
