#include <stdio.h>

#define v 5

void init(int arr[][v]) {
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            arr[i][j] = 0;
        }
    }
}

void insertEdge(int arr[][v], int i, int j) {
    arr[i][j] = 1; // Shows the code for undirected unweighted graph
    arr[j][i] = 1; // Shows the code for undirected unweighted graph
}

void printAdjMatrix(int arr[][v]) {
    int i, j;
    for (i = 0; i < v; i++) {
        printf("%d: ", i);
        for (j = 0; j < v; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[v][v];
    init(adjMatrix);

    insertEdge(adjMatrix, 1, 2);
    insertEdge(adjMatrix, 1, 6);
    insertEdge(adjMatrix, 2, 3);
    insertEdge(adjMatrix, 2, 5);
    insertEdge(adjMatrix, 2, 6);
    insertEdge(adjMatrix, 3, 5);
    insertEdge(adjMatrix, 3, 4);
    insertEdge(adjMatrix, 5, 6);
    
    printAdjMatrix(adjMatrix);
    return 0;
}
