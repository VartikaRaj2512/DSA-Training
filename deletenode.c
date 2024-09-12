#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deletenode(struct Node* n1, int value) {
    struct Node* p1 = n1;
    struct Node* p2 = n1->next;

    // Special case: If the node to be deleted is the first node
    if (p1->data == value) {
        n1 = p1->next; // Update head to the next node
        free(p1);      // Free memory of the node to be deleted
        return n1;     // Return the updated head
    }

    // General case: Traverse the list to find the node to be deleted
    while (p2 != NULL && p2->data != value) {
        p1 = p1->next;
        p2 = p2->next;
    }

    // If node with 'value' is found, delete it
    if (p2 != NULL) {
        p1->next = p2->next; // Update the link of previous node
        free(p2);            // Free memory of the node to be deleted
    }

    return n1; // Return the head of the updated list
}

void printList(struct Node* p) {
    while (p != NULL) {
        printf("%d \n", p->data);
        p = p->next;
    }
}

int main() {
    struct Node* n1;
    struct Node* n2;
    struct Node* n3;

    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 100;
    n1->next = n2;

    n2->data = 200;
    n2->next = n3;

    n3->data = 300;
    n3->next = NULL;

    printList(n1);

    n1 = deletenode(n1, 200);

    printf("=========\n");
    printList(n1);

    return 0;
}
