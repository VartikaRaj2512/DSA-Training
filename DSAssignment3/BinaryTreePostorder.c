#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function for postorder traversal
void postorderTraversal(struct node* node) {
    if (node == NULL) {
        return;
    }
    // Recursively traverse the left subtree
    postorderTraversal(node->left);
    // Recursively traverse the right subtree
    postorderTraversal(node->right);
    // Visit the root (current node)
    printf("%d ", node->data);
}

int main() {
    // Construct the binary tree
    struct node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    // Perform postorder traversal
    printf("Postorder traversal is: ");
    postorderTraversal(root);

    return 0;
}
