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
void inorderTraversal(struct node* root){
    if(root==NULL)
    return;
    inorderTraversal(root->left);
    printf("%d",root->data);
    inorderTraversal(root->right);
}
struct node* insertNode(struct node* root, int value){
    if(root==NULL)
    return createNode(value); //null means no node present in tree so we need to create node
    if(value<root->data){
        root->left=insertNode(root->left, value);
    }
    else{
        root->right=insertNode(root->right,value);
    }
    return root;
}
struct node* searchNode(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root; // Either the node is not found or the node with the given value is found
    }
    if (value < root->data) {
        return searchNode(root->left, value); // Search in the left subtree
    } else {
        return searchNode(root->right, value); // Search in the right subtree
    }
}
struct node* searchNode(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root; // Either the node is not found or the node with the given value is found
    }
    if (value < root->data) {
        return searchNode(root->left, value); // Search in the left subtree
    } else {
        return searchNode(root->right, value); // Search in the right subtree
    }
}
struct node* deleteNode(struct node* root,int value) {
    if (root == NULL) {
        return root;
    }
if (value < root->data) {
        return deleteNode(root->left, value); // delete in left subtree
    } else if (value > root->data) {
        return deleteNode(root->right, value);// delete in right subtree  
    }
    else{
//use find min func.
    }
    // node has 1 child either left or right child
    //  if (root->left == NULL) {
    //         struct node* temp = root->right;
    //         free(root);
    //         return temp;
    //     } else if (root->right == NULL) {
    //         struct node* temp = root->left;
    //         free(root);
    //         return temp;
    //     }
    //node has both child


}

int main() {
    struct node* root = NULL;
    root = insertNode(root, 10);
   root = insertNode(root, 13);
  root =  insertNode(root, 9);
   root = insertNode(root, 20);
   root = insertNode(root, 15);
   root = insertNode(root, 12);
 printf("Inorder traversal of the BST is:");
    inorderTraversal(root);
     int valueToSearch = 20;
    struct node* result = searchNode(root, valueToSearch);
    if (result != NULL) {
        printf("Value %d found in the BST.\n", valueToSearch);
    } else {
        printf("Value %d not found in the BST.\n", valueToSearch);
    }
     int valueToDelete = 13;
    root = deleteNode(root, valueToDelete);

    printf("Inorder traversal after deleting %d: ", valueToDelete);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
