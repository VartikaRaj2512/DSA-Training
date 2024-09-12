#include <stdio.h>  
#include <stdlib.h>  
#include<stdbool.h>
  
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

