#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

struct GraphEdge {
    int start, end, weight;
};

struct GraphEdge edges[MAX_EDGES];

int parent[MAX_EDGES];

int findRoot(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findRoot(parent[node]);
}

void unionNodes(int rootA, int rootB) {
    parent[rootB] = rootA;
}

int compareEdges(const void *a, const void *b) {
    return ((struct GraphEdge *)a)->weight - ((struct GraphEdge *)b)->weight;
}

void kruskalAlgorithm(int totalEdges, int totalVertices) {
    qsort(edges, totalEdges, sizeof(edges[0]), compareEdges);

    for (int i = 0; i < totalVertices; i++)
        parent[i] = i;

    printf("\nPrashant Paudel\n");
    printf("Minimum Spanning Tree (Kruskal's Algorithm):\n");

    int edgeCount = 0, i = 0;
    while (edgeCount < totalVertices - 1 && i < totalEdges) {
        struct GraphEdge nextEdge = edges[i++];

        int rootA = findRoot(nextEdge.start);
        int rootB = findRoot(nextEdge.end);

        if (rootA != rootB) {
            printf("%d - %d : %d\n", nextEdge.start, nextEdge.end, nextEdge.weight);
            unionNodes(rootA, rootB);
            edgeCount++;
        }
    }
}

int main() {
    int totalVertices, totalEdges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &totalVertices, &totalEdges);

    printf("Enter edges (start end weight):\n");
    for (int i = 0; i < totalEdges; i++)
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].weight);

    kruskalAlgorithm(totalEdges, totalVertices);
    return 0;
}

