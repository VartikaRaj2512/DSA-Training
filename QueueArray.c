#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int front=-1,rear=-1;
int queue[maxsize];

void insert(int item)
{
    if(rear== maxsize-1){
        printf("\n Cannot add element");
        return;
    }
if(front==-1 && rear==-1)
{
    front=0;
    rear=0;
}
else{
    rear=rear+1;
}
queue[rear]=item;
printf("\n element inserted");
}
void delete(){
    int item;
    if(front==-1 || front>rear){
        printf("\n Underflow");
        return;
    }
    else{
        item=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=front+1;
        }
        printf("\n value deleted");
    }
}
void display(){
    int i;
    if(rear==-1){
        printf("\n empty queue");
    }
    else{
        printf("\n printing values ....\n");
        for(i=front;i<=rear;i++){
            printf("\n%d\n",queue[i]);
        }
    }
}

int main()
{
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);
    display();
    delete();
    delete();
    delete();
    display();
    return 0;
}
