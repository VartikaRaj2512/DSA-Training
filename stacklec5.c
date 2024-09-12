#include<stdio.h>
#include<stdlib.h>
#define MAX 100 //size defining

//stack structure definition with array
typedef struct{
    int arr[MAX];
    int top;
}Stack;

//function to initialize the stack
void initialize(Stack* s){
s->top=-1; //condition for empty stack
}

//function to check if stack is empty
int isEmpty(Stack* s){
    return s->top==-1;
}

//function to check if stack is full
int isFull(Stack* s){
    return s->top==MAX-1;
}

//Function to push an element onto the stack
void push(Stack* s,int value){
    if(isFull(s)){
        printf("Stack is overflow\n");
        return;
    }
    s->arr[++(s->top)]=value;
}

//Function to pop an element from the stack
int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int main(){
    Stack s;
    initialize(&s);

    
    push(&s,10);
    push(&s,20);
    push(&s,30);

}
