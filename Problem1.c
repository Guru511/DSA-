#include<stdio.h>
#include <string.h>
#define N 5         
#define STR_LEN 50  
char queue[N][STR_LEN];  
int front=-1;
int rear=-1;
void enqueue(char drink[]){
   
    if(front==-1 && rear==-1){
        front=rear=0;
        strcpy(queue[rear], drink);
    }else if((rear+1)%N==front){
        printf("queue is full");
    }else{
        rear=(rear+1)%N;
        strcpy(queue[rear], drink); 
    }
}
void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("queue is empty");
    }else{
        while(i!=rear){
            printf("%s ",queue[i]);
            i=(i+1)%N;
        }
        printf("%s \n",queue[i]);
    }
}
void  main(){
    char drink[STR_LEN];
    for(int i=0;i<3;i++){
        printf("enter the name of drink that you wish to drink \n ");
        fgets(drink, sizeof(drink),stdin); 
        enqueue(drink);
   
    }
         display();
} 