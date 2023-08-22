#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    if (graph->adjacencyList == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}
void addEdge(struct Graph* graph, int source, int destination) {
    struct Node* newNode = createNode(destination);
    newNode->next = graph->adjacencyList[source];
    graph->adjacencyList[source] = newNode;
    newNode = createNode(source);
    newNode->next = graph->adjacencyList[destination];
    graph->adjacencyList[destination] = newNode;
}
void BFS(struct Graph* graph, int startVertex) {
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    struct Node* queue[graph->numVertices];
    int front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = graph->adjacencyList[startVertex];
    printf("Breadth First Traversal (starting from vertex %d):\n", startVertex);
    while (front < rear) {
        struct Node* currentNode = queue[front++];
        printf("%d ", currentNode->data);
        struct Node* temp = currentNode;
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = graph->adjacencyList[adjVertex];
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    int startVertex = 0;
    BFS(graph, startVertex);
    return 0;
}
