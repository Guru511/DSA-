#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dream{
    char data[50];
    struct dream *next;
};
struct dream *top=0;
void push(char dreamlayer[]){
    struct dream *newdream;
    newdream=(struct dream *)malloc(sizeof(struct dream));
    strcpy(newdream->data,dreamlayer);
    newdream->next=top;
    top=newdream;
}
void display(){
    struct dream *temp;
    temp=top;
    if(top==0){
    printf("the stack is empty");
    }else{
        while(temp!=0){
            printf("\n%s \n",temp->data);
            temp=temp->next;
        }
    }
}
void pop(){
    struct dream *temp;
    temp=top;
    if(top==0){
        printf("the stack is empty");
    }else{
        printf("%s ",top->data);
        top=top->next;
        free(temp);
    }
}
void main(){
    char dreamlayer[100];
    for(int i=0;i<4;i++){
        printf("enter the dream layer :\n");
        fgets(dreamlayer,sizeof(dreamlayer),stdin);
        push(dreamlayer);
    }
    display();
    pop();
    pop();
}