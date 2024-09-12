// #include<stdio.h>
// #define max 5
// void bfs(int adj[][max], int visited[], int start){
//     int queue[max],rear=-1,front=-1,i,j;
//     for(i=0;i<max;i++){
//         visited[i]=0;
//     }
// queue[++rear]=start;
// ++front;
// visited[start]=1;
// while(rear>=front)
// {
//     start=queue[front++];
//     printf("%d",start);
//     for(j=0;j<max;j++){
//         if(adj[start][j]&& visited[j]==0){
//         queue[++rear]=j;
//      visited[j]=1;
//         }
//     }
// }
// }
// void init(int arr[][max]) {
//     int i, j;
//     for (i = 0; i < max; i++) {
//         for (j = 0; j < max; j++) {
//             arr[i][j] = 0;
//         }
//     }
// }
// void insertEdge(int arr[][max], int i, int j) {
//     if (i < max && j < max) {
//         arr[i][j] = 1; // For directed graph
//     }
// }
// void printAdjMatrix(int arr[][max]) {
//     int i, j;
//     for (i = 0; i < max; i++) {
//         printf("%d: ", i);
//         for (j = 0; j < max; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main(){
//      int adjMatrix[max][max];
//     init(adjMatrix);

//     insertEdge(adjMatrix, 1, 2);
//     insertEdge(adjMatrix, 1, 6);
//     insertEdge(adjMatrix, 2, 3);
//     insertEdge(adjMatrix, 2, 6);
//     insertEdge(adjMatrix, 3, 4);
//     insertEdge(adjMatrix, 3, 5);
//     insertEdge(adjMatrix, 4, 5);
//     insertEdge(adjMatrix, 5, 2);
//     insertEdge(adjMatrix, 5, 6);
    
//     printAdjMatrix(adjMatrix);
//     int visited[max];
//     printf("BFS traversal is:");
//     bfs(adjMatrix,visited,start);


//     return 0;
// }
#include<stdio.h>
#define MAX 7

void bfs(int adj[][MAX], int visited[], int start) {
    int queue[MAX], rear = -1, front = -1, i, j;

    for(i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while(rear >= front) {
        start = queue[front++];
        printf("%d ", start);
        
        for(j = 0; j < MAX; j++) {
            if(adj[start][j] && visited[j] == 0) {
                queue[++rear] = j;
                visited[j] = 1;
            }
        }
    }
}

void init(int arr[][MAX]) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            arr[i][j] = 0;
        }
    }
}

void insertEdge(int arr[][MAX], int i, int j) {
    if (i < MAX && j < MAX) {
        arr[i][j] = 1; // For undirected graph
        arr[j][i] = 1; // Add this line to make it undirected
    }
}

void printAdjMatrix(int arr[][MAX]) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        printf("%d: ", i);
        for (j = 0; j < MAX; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[MAX][MAX];
    init(adjMatrix);

    insertEdge(adjMatrix, 0, 1);
    insertEdge(adjMatrix, 0, 4);
    insertEdge(adjMatrix, 1, 2);
    insertEdge(adjMatrix, 1, 3);
    insertEdge(adjMatrix, 1, 4);
    insertEdge(adjMatrix, 2, 3);
    insertEdge(adjMatrix, 3, 4);
    // insertEdge(adjMatrix, 5, 2);
    // insertEdge(adjMatrix, 5, 6);
    
    printAdjMatrix(adjMatrix);

    int visited[MAX];
    int start = 1; // Define the starting vertex


    printf("BFS traversal is: ");
    // bfs(adjMatrix, visited, start);
    bfs(adjMatrix, visited,1);


    return 0;
}
