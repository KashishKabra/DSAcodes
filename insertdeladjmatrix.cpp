
#include <stdio.h>
#define V 4

void addEdge(int arr[][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1; 
}
void delEdge(int arr[][V], int i, int j) {
    arr[i][j] = 0;
    arr[j][i] = 0; 
}
void init(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}
void printAdjMatrix(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        printf("%d: ", i);
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int adjMatrix[V][V];

    init(adjMatrix);
    printAdjMatrix(adjMatrix);
    printf("\n");
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 3, 1);
    addEdge(adjMatrix, 1, 1);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 2, 1);

    printAdjMatrix(adjMatrix);
	printf("\n");
    // Deleting an edge between vertex 0 and 1
    delEdge(adjMatrix, 0, 1);
    printAdjMatrix(adjMatrix);
    return 0;
}
