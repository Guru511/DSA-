#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[50];
    struct node *next;
};
struct node *rear=0;
struct node *front=0;
void enqueue(char crew[]){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->data,crew);
    newnode->next=0;
    if(front==0 && rear==0){
        front=rear=newnode;
    }else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    struct node *temp;
    temp=front;
    if(front==0 &&  rear==0){
        printf("the queue is empty");
    }else{
        printf("%s ",temp->data);
        front=front->next;
        free(temp);
    }
}
void display(){
    struct node *temp;
    temp=front;
    if(front ==0 && rear==0){
        printf("the queu is empty\n");

    }else{
        printf("the crew members :\n ");
        while(temp!=0){
            printf("%s ",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    char crew[100];
    for(int i=0;i<3;i++){
        printf("enter the names of crew members : \n ");
        fgets(crew,sizeof(crew),stdin);
        printf("\n");
        enqueue(crew);
    }
    display();
    printf("\n dequeued crew is : ");
    dequeue();
}

