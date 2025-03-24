#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char data[50];
    struct node *left;
    struct node*right;
};
struct node *root=0;
void insert(char location[]){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->data,location);
    temp->left=0;
    temp->right=0;
    
    if(root==0){
        root=temp;
        return;
    }else{
    struct node *parent=NULL;
        struct node *current=root; 
   
        while(current!=0){
            parent=current;
            if(strcmp(location,current->data)<0){
                current=current->left;
            }else{
                current=current->right;
            }
        }
    
    if(strcmp(location,parent->data)<0){
        parent->left=temp;
    }else{
        parent->right=temp;
    }
    }
}
struct node* search(struct node *root, char key[]){
    if (root == NULL) {
        return NULL; 
    }
    if (strcmp(key, root->data) == 0) { 
        return root; 
    } 
    else if (strcmp(key, root->data) < 0) {
        return search(root->left, key); 
    } 
    else {
        return search(root->right, key);
    }
}
void inorder(struct node *root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%s\n",root->data);
    inorder(root->right);
}

void main (){
    int n;
    char location[50];
    printf("enter the number of location :\n ");
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++){
        printf("enter the location %d :",i+1);
        fgets(location,sizeof(location),stdin);
        location[strcspn(location,"\n")]=0;
        insert(location);
    }
    printf("inorder :");
    inorder (root);
    
    printf("enter location to search \n");
    fgets(location,sizeof(location),stdin);
    location[strcspn(location,"\n")]=0;
    search(root,location);
    if(search(root,location)){
        printf("%s location is present\n",location);
    }else{
        printf("%s location is not present\n",location);
    }
    
}

// Castle Byers
// Hawkins Lab
// Hawkins Middle School
// Mind Flayer's Nest
// Starcourt Mall
// The Void
// Wheeler House
// Henderson House
// Hopper’s Cabin