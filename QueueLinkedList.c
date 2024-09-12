#include<stdio.h>
#include<stdlib.h>
struct node{  //create node
    int data;
    struct node* next;
};
struct node* front;
struct node* rear;
void insert(int data){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("overflow\n");
        return ;
    }
    else{
        ptr->data=data;
        if(front==NULL){
            front=ptr;
            rear=ptr;
            front->next=NULL;
            rear->next=NULL;
        }
        else{
            rear ->next=ptr;
            rear = ptr;
            rear->next=NULL;
        }
    }
}
void delete(){
    struct node*ptr;
    if (front==NULL){
        printf("underflow\n");
        return;
    }
    else{
        ptr=front;
        front=front->next;
        free(ptr);
    }
}
void display(){
    struct node *ptr;
    ptr=front;
    if (front==NULL){
        printf("Queue is Empty\n");

    }
    else{
        printf("element int the queue are: \n");
        while(ptr !=NULL){
            printf("%d\n", ptr -> data);
            ptr=ptr->next;
        }
    }
}
void main(){
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);
    display();
    delete();
    display();
// return 0;
}