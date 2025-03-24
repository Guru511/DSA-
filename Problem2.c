#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char data[50];
    struct node *link;
};
struct node *top=0;
void push(char destination[]){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    strcpy(newnode->data,destination);
    newnode->link=top;
    top=newnode;
}
void display(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("stack is empty\n");
    }else{
        while(temp!=0){
            printf("%s ",temp->data);
            temp = temp->link;
        }
    }
}
void pop(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("stack is empty\n");
    }else{
        printf("\n%s ",top->data);
        top=top->link;
        free(temp);
    }
}
void main(){
    char destination[50];
  
    for(int i=0;i<3;i++){
        printf("enter the destination u want to keep track of\n ");
        fgets(destination, sizeof(destination),stdin);
        // destination[strcspn(destination, "\n")] = '\0';
        push(destination);
    
    
    }
   
    display();
    pop();

}