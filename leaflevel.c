#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
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

// Utility function to check if a node is a leaf
int isLeaf(struct Node* node) {
    return (node->left == NULL && node->right == NULL);
}

// Utility function to find the height of the tree
int findHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to check if all leaf nodes are at the same level
int checkLeavesLevel(struct Node* node, int level, int* leafLevel) {
    if (node == NULL)
        return 1;

    // If this node is a leaf
    if (isLeaf(node)) {
        // If this is the first leaf node visited, set the leaf level
        if (*leafLevel == 0) {
            *leafLevel = level;
            return 1;
        }

        // If this is not the first leaf node, check if it is at the same level as the first leaf node
        return (level == *leafLevel);
    }

    // Recursively check the left and right subtrees
    return checkLeavesLevel(node->left, level + 1, leafLevel) &&
           checkLeavesLevel(node->right, level + 1, leafLevel);
}

// Main function to check if all leaf nodes are at the same level
int areLeavesAtSameLevel(struct Node* root) {
    int leafLevel = 0;
    return checkLeavesLevel(root, 1, &leafLevel);
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    //following nodes have leaf nodes not at same level
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);

    // following nodes have leaf nodes at same level
    
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);

    if (areLeavesAtSameLevel(root))
        printf("All leaf nodes are at the same level.\n");
    else
        printf("Leaf nodes are not at the same level.\n");

    return 0;
}
