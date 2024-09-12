#include <stdio.h>

#define v 7 // Number of vertices

void init(int arr[][v]) {
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            arr[i][j] = 0;//initial value when no edge between nodes 
            // arr[i][j]=-1;//initial val is -1 instead of 0 for case-weight=0
        }
    }
}

void insertEdge(int arr[][v], int i, int j,int weight) {
    if (i < v && j < v) {
        // arr[i][j] = weight; // For undirected graph
        // arr[j][i] = weight; 
        // for directed weighted graph
        arr[i][j] = weight; // For undirected graph
        arr[j][i] = 0; 
        //(-1)used when weight is 0
        // arr[i][j] = weight; // For undirected graph
        // arr[j][i] = -1;


    }
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

    insertEdge(adjMatrix, 1, 2,40);
    insertEdge(adjMatrix, 1, 6,30);
    insertEdge(adjMatrix, 2, 3,20);
    insertEdge(adjMatrix, 2, 6,10);
    insertEdge(adjMatrix, 3, 4,15);
    insertEdge(adjMatrix, 3, 5,25);
    insertEdge(adjMatrix, 4, 5,35);
    insertEdge(adjMatrix, 5, 2,5);
    insertEdge(adjMatrix, 5, 6,45);
    
    printAdjMatrix(adjMatrix);
    return 0;
}
