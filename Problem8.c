#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char data[50];
    struct node *left;
    struct node *right;
};
struct node * create (){
    char value[50];
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter name(-1 for no node)");
    fgets(value,sizeof(value),stdin);
   
    value[strcspn(value, "\n")] = 0;
    if (strcmp(value, "-1") == 0) {
        return 0;
    }
    strcpy(newnode->data,value);
  
    printf("enter left child of %s \n",value);
    newnode->left=create();
    printf("enter the right child of %s \n",value);
    newnode->right=create();
    return newnode;

}

void preorder(struct node *root){
    if(root==0){
        return;
    }else{
        printf("%s ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root==0){
        return;
    }else{
        postorder(root->left);
        postorder(root->right);
        printf("%s ",root->data);
    }
}void inorder(struct node *root){
    if(root==0){
        return;
    }else{
        inorder(root->left);
        printf("%s ",root->data);
        inorder(root->right);
    }
}
void main(){
    struct node *root;
    root=0;
    root=create();
   
    printf("preorder:\n");
    preorder(root);
    printf("\n inorder:\n");
    inorder(root);
    printf("\n postorder:\n");
    postorder(root);
}
