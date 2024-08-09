#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for binary tree node.
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to search a node in the binary tree
bool searchTree(struct TreeNode* root, int key) {
    // Base case: root is null or key is present at root
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }

    // Key is greater than root's data, search in the right subtree
    if (key > root->data) {
        return searchTree(root->right, key);
    }
    // Key is smaller than root's data, search in the left subtree
    return searchTree(root->left, key);
}

// Function to print the binary tree in-order (for testing purposes)
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    // Create a binary tree
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // Print the binary tree
    printf("In-order Traversal of the Binary Tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for a node in the binary tree
    int key = 7; // Change this value to test different keys
    if (searchTree(root, key)) {
        printf("Node with value %d found in the tree.\n", key);
    } else {
        printf("Node with value %d not found in the tree.\n", key);
    }

    return 0;
}
