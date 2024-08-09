#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, the new node becomes the head
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    head = prev;
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d-", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to validate user input
int getValidInput() {
    int value;
    char term;
    if (scanf("%d%c", &value, &term) != 2 || term != '\n') {
        while (getchar() != '\n');  // Clear input buffer
        printf("Invalid input. Please enter an integer value: ");
        return getValidInput();
    }
    return value;
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the linked list: ");
    n = getValidInput();

    if (n <= 0) {
        printf("The number of elements must be greater than zero.\n");
        return 1; // Exit if the number of elements is not positive
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        data = getValidInput();
        appendNode(&head, data);
    }

    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    printf("Reversed linked list: ");
    printList(head);

    return 0;
}
