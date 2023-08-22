#include <stdio.h>
#include <stdlib.h>
#define V 5 
#define E 7 
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, rank;
};
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
void kruskalMST(struct Edge edges[]) {
    struct Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    struct Edge result[V];
    int e = 0, i = 0;
    qsort(edges, E, sizeof(struct Edge), compareEdges);
    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
    printf("Edge \t Weight\n");
    for (int i = 0; i < e; i++) {
        printf("%d - %d \t %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}
int main() {
    struct Edge edges[E] = {
        {0, 1, 2}, {0, 3, 6}, {1, 3, 8},
        {1, 4, 5}, {1, 2, 3}, {2, 4, 7},
        {3, 4, 9}
    };
    kruskalMST(edges);
    return 0;
}
