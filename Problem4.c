#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct member{
    char members[50];
    struct member *next;
};
struct member *head=NULL;
void add_at_end(char name[]){
    struct member *newmember, *temp;
    newmember=(struct member *)malloc(sizeof(struct member));
    strcpy(newmember->members,name);
  
    newmember->next=0;
  
    
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newmember;
    temp=newmember;
    
}
void display(){
    struct member *temp;
    temp=head;
    while(temp!=0){
        printf("%s ",temp->members);
        temp=temp->next;
    }
}
void main(){
    char name[100];
    int choice=1;
    while(choice){
    struct member *newmember, *temp;
    newmember=(struct member *)malloc (sizeof( struct member));
    printf("enter the name of the members of fellowhip : \n");
    fgets(name,sizeof(name),stdin);
    strcpy(newmember->members,name);
  
    newmember->next=0;
    if(head==0){
         head=temp=newmember;
    }else{
        temp->next=newmember;
        temp=newmember;
    }
    printf("To add next fellowship member enter 1 \n to stop enter 0 \n");
    scanf("%d",&choice);
    getchar();
}
// 
display();
printf("do you want to enter nother member\n");
fgets(name,sizeof(name),stdin);
add_at_end(name);
printf("final list of members : \n");
display();
}