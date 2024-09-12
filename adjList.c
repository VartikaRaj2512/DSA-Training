// #include<stdio.h>
// #include<stdlib.h>
// /**/
#include <stdio.h>  
#include <stdlib.h>  
  
// A structure to represent a node in the adjacency list  
struct node {  
    int vertex;  
    struct node* next;  
};  
  
// A structure to represent the adjacency list  
struct adj_list {  
    struct node* head;  
};  
  
// A structure to represent the graph  
struct graph {  
    int num_vertices;  
    struct adj_list* adj_lists;  
    int* visited;  
};  
  
// Create a new node in the adjacency list  
struct node* new_node(int vertex) {  
    struct node* new_node = (struct node*)malloc(sizeof(struct node));  
new_node->vertex = vertex;  
new_node->next = NULL;  
    return new_node;  
}  
  
// Create a graph with n vertices  
struct graph* create_graph(int n) {  
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));  
    graph->num_vertices = n;  
    graph->adj_lists = (struct adj_list*)malloc(n * sizeof(struct adj_list));  
    graph->visited = (int*)malloc(n * sizeof(int));  
  
    int i;  
    for (i = 0; i< n; i++) {  
        graph->adj_lists[i].head = NULL;  
        graph->visited[i] = 0;  
    }  
  
    return graph;  
}  
  
// Add an edge to the graph  
void add_edge(struct graph* graph, int src, int dest) {  
    // Add an edge from src to dest  
    struct node* new_node1 = new_node(dest);  
    new_node1->next = graph->adj_lists[src].head;  
    graph->adj_lists[src].head = new_node1;  
  
    // Add an edge from dest to src  
    struct node* new_node2 = new_node(src);  
    new_node2->next = graph->adj_lists[dest].head;  
    graph->adj_lists[dest].head = new_node2;  
}  
  
// BFS traversal of the graph starting from vertex v  
void bfs(struct graph* graph, int v) {  
    // Create a queue for BFS  
    int queue[1000];  
    int front = -1;  
    int rear = -1;  
  
    // Mark the current node as visited and enqueue it  
    graph->visited[v] = 1;  
    queue[++rear] = v;  
  
    // Loop to visit all the vertices in the graph  
    while (front != rear) {  
        // Dequeue a vertex from the queue and print it  
        int current_vertex = queue[++front];  
printf("%d ", current_vertex);  
  
        // Get all the neighbors of the dequeued vertex  
        struct node* temp = graph->adj_lists[current_vertex].head;  
        while (temp != NULL) {  
            int adj_vertex = temp->vertex;  
  
            // If the neighbor has not been visited, mark it as visited and enqueue it  
            if (graph->visited[adj_vertex] == 0) {  
                graph->visited[adj_vertex] = 1;  
                queue[++rear] = adj_vertex;  
            }  
  
            temp = temp->next;  
        }  
    }  
}  
  
int main() {  
    // Create a graph with 6 vertices  
    struct graph* graph = create_graph(6);  
  
    // Add edges to the graph  
add_edge(graph, 0, 1);  
add_edge(graph, 0, 2);  
add_edge(graph, 1, 3);  
add_edge(graph, 1, 4);  
add_edge(graph, 2, 4);  
add_edge(graph, 3, 4);  
add_edge(graph, 3, 5);  
add_edge(graph, 4,5);  
        // Perform BFS traversal starting from vertex 0  
printf("BFS traversal starting from vertex 0: ");  
bfs(graph, 0);  
  
    return 0;  
}