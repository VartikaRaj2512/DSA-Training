#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if two binary trees are identical
int areIdentical(struct Node* root1, struct Node* root2) {
    // Both trees are empty
    if (root1 == NULL && root2 == NULL)
        return 1;
    
    // Both trees are non-empty, compare them
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) &&
               areIdentical(root1->left, root2->left) &&
               areIdentical(root1->right, root2->right);
    }
    
    // One tree is empty and the other is not
    return 0;
}

// Function to build a binary tree from user input
struct Node* buildTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);
    
    if (data == -1) return NULL;
    
    struct Node* root = newNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = buildTree();
    printf("Enter right child of %d:\n", data);
    root->right = buildTree();
    
    return root;
}

// Driver code
int main() {
    printf("Build the first binary tree:\n");
    struct Node* root1 = buildTree();
    
    printf("Build the second binary tree:\n");
    struct Node* root2 = buildTree();
    
    if (areIdentical(root1, root2))
        printf("The two binary trees are identical.\n");
    else
        printf("The two binary trees are not identical.\n");
    
    return 0;
}
