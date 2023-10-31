
#include <stdio.h>
#include <stdlib.h>

// Node to store adjacency list
struct AdjNode {
    int vertex;//vertex number
    struct AdjNode* next;
};

// Adjacency List representation
struct AdjList {
    int v;//no of vertices
    struct AdjNode** graph;//pointere to AdjNode objects
};

// Function to create a new adjacency list node
struct AdjNode* newAdjNode(int data) {
    struct AdjNode* newNode = (struct AdjNode*)malloc(sizeof(struct AdjNode));
    newNode->vertex = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an adjacency list with 'v' vertices
struct AdjList* createGraph(int vertices) {
    struct AdjList* graph = (struct AdjList*)malloc(sizeof(struct AdjList));
    graph->v = vertices;
    graph->graph = (struct AdjNode**)malloc(vertices * sizeof(struct AdjNode*));
    for (int i = 0; i < vertices; ++i)
        graph->graph[i] = NULL;
    return graph;
}

// Function to add an edge from a source vertex to a destination vertex
void addEdge(struct AdjList* graph, int source, int destination) {
    struct AdjNode* node = newAdjNode(destination);
    node->next = graph->graph[source];
    graph->graph[source] = node;
}

// Function to add a vertex between two vertices
void addVertex(struct AdjList* graph, int vk, int source, int destination) {
    addEdge(graph, source, vk);
    addEdge(graph, vk, destination);
}

// Function to print the graph
void printGraph(struct AdjList* graph) {
    for (int i = 0; i < graph->v; ++i) {
        printf("%d ", i);
        struct AdjNode* temp = graph->graph[i];
        while (temp != NULL) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to delete a vertex
void delVertex(struct AdjList* graph, int k) {
    // Iterate through all the vertices of the graph
    for (int i = 0; i < graph->v; ++i) {
        struct AdjNode* temp = graph->graph[i];
        if (i == k) {
            graph->graph[i] = temp->next;
            free(temp);
            temp = graph->graph[i];
        }
        // Delete the vertex using linked list concept
        while (temp != NULL) {
            if (temp->vertex == k) {
                break;
            }
            struct AdjNode* prev = temp;
            temp = temp->next;
            if (temp == NULL) {
                continue;
            }
            prev->next = temp->next;
            free(temp);
            temp = NULL;
        }
    }
}

int main() {
    int V = 6;
    struct AdjList* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 3);

    printf("Initial adjacency list\n");
    printGraph(graph);

    // Add vertex
    addVertex(graph, 5, 3, 2);
    printf("Adjacency list after adding vertex\n");
    printGraph(graph);

    // Delete vertex
    delVertex(graph, 4);
    printf("Adjacency list after deleting vertex\n");
    printGraph(graph);

    return 0;
}


