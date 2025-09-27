#include<stdio.h>
#include<stdlib.h>

typedef struct q{
    int data;
    struct q * next;
} q;

q* front = NULL;
q* rear= NULL;
void enqueue(int val){
    q* newnode= malloc(sizeof(q));
    newnode->data=val;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next= newnode;
        rear=newnode;
    }
}

void dequeue(){
    if(front==NULL && rear==NULL){
        printf("Queue underflow\n");
    }    
    if(front==rear){
        free(front);
        front=rear=NULL;
    }
    else{
        q*temp=front;
        front=temp->next;
        printf("The dequeued element is %d\n", temp->data);
        free(temp);
    }
}
void display(){
    if(rear==NULL && front== NULL){
        printf("The queue is empty\n");
    }
    else{
    q* temp= front;
    while(temp->next!=NULL){
        printf("%d-> ", temp->data);
        temp=temp->next;
    }        
    printf("NULL\n");
    }
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("The queue is:\n");
    display();

    dequeue();
    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue();
    display();
    
    return 0;
}
