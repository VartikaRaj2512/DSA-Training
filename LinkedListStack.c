#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void push(int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL){
   printf("Cannot push the element");
    }
    else{
        if(head==NULL){
            ptr->data=data;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            ptr->data=data;
            ptr->next=head;
            head=ptr;
        }
    }
    
}
void pop()
{
    struct Node* ptr;
    if(head== NULL)
    {
        printf("Stack underflow");
    }
    else{
        ptr=head;
        head=head->next;
        free(ptr);
    }
}
void displayElements(){
    struct Node* ptr;
    ptr=head;
    if(ptr==NULL){
        printf("Stack is empty");
    }
    else{
        printf("Printing Stack elements\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main()
{
    push(11);
    push(12);
    push(13);
    push(14);
    push(15);
    displayElements();
    pop();
    pop();
    pop();
    displayElements();
    return 0;
} 