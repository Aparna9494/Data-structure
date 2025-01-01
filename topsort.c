#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int** adjMatrix;
} Graph;

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjMatrix = (int**) malloc(numVertices * sizeof(int*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*) malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

// Function to perform topological sorting using DFS
void topologicalSortUtil(Graph* graph, int vertex, int* visited, int* stack, int* top) {
    visited[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            topologicalSortUtil(graph, i, visited, stack, top);
        }
    }

    stack[(*top)++] = vertex;
}

// Function to perform topological sorting
void topologicalSort(Graph* graph) {
    int* visited = (int*) malloc(graph->numVertices * sizeof(int));
    int* stack = (int*) malloc(graph->numVertices * sizeof(int));
    int top = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (visited[i] == 0) {
            topologicalSortUtil(graph, i, visited, stack, &top);
        }
    }

    printf("Topological Sorting Order: ");
    for (int i = graph->numVertices - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(visited);
    free(stack);
}


/*
// Function to print the adjacency matrix

void printAdjMatrix(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
*/
int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    topologicalSort(graph);

    return 0;
}
