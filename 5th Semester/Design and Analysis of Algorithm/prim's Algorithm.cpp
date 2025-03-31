#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

void displayMST(int parent[], int graph[MAX_NODES][MAX_NODES], int vertices) {
    printf("\nPrashant Paudel\n");
    printf("Minimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
}

int findMinKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, index;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], index = v;

    return index;
}

void primAlgorithm(int graph[MAX_NODES][MAX_NODES], int vertices) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    int mstSet[MAX_NODES];

    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = findMinKey(key, mstSet, vertices);
        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    displayMST(parent, graph, vertices);
}

int main() {
    int vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    primAlgorithm(graph, vertices);
    return 0;
}
