#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node{
    int is_occupied;
    char entity_type;
    int entity_id;
    
};
struct entity{
    char entity_type;
    char  entity_close;
    int  entity_id;
    int count;
};
int main(){
    int rows , coloumns; 
    printf("enter the number of rows");
    scanf("%d",&rows);
    printf("enter the number of coloumns");
    scanf("%d",&coloumns);

    struct node **arr;
    arr=(struct node **)malloc(rows  *sizeof(struct node*));
    for (int i=0;i<rows;i++){
        arr[i]=(struct node *)malloc(coloumns * sizeof(struct node));

    }
    printf("enter the elements :\n");
    for (int i=0;i<rows;i++){
        for (int j=0;j<coloumns;j++){
        
            printf("enter 0 0r 1 to determine the cell is occupied or not");
            scanf("%d",&arr[i][j]. is_occupied);
            if(arr[i][j].is_occupied==0){
                arr[i][j].entity_type= '-';
                arr[i][j].entity_id=0;
                printf("the cell is not occupied\n");
            }else{
                printf("cell is occupied\n"); 
                printf("enter the entity type :\n");
            scanf(" %c",&arr[i][j].entity_type);
            // fgets(arr[i][j].entity_type,sizeof(arr[i][j].entity_type),stdin);
        

            printf("enter the entity id\n");
            scanf("%d",&arr[i][j].entity_id);   
            }
        }

    }
    
    printf("the elements in the array :\n");
    for (int i=0;i<rows;i++){
    for (int j=0;j<coloumns;j++){
        if(arr[i][j].is_occupied){
        printf(" %c-%d\t",arr[i][j].entity_type ,arr[i][j].entity_id);
        }else{
            printf("-\t");
        }
    }
    printf("\n");
}
struct entity *unique_entity,*temp;
unique_entity=(struct entity *)malloc(rows * coloumns *sizeof(struct entity));
temp=(struct entity *)malloc(rows * coloumns *sizeof(struct entity));
int unique_count=0;
int temp_count=0;
for (int i=0; i<rows; i++) {
    for (int j=0; j<coloumns; j++) {
        if (arr[i][j].is_occupied) {
            bool is_duplicate = false;
            for (int k=0; k<unique_count; k++) {
                if (arr[i][j].entity_type == unique_entity[k].entity_type) {
                    unique_entity[k].count++;
                    temp[temp_count].entity_type=arr[i][j].entity_type;
                    
                    temp[temp_count].entity_id=arr[i][j].entity_id;
                    
                    temp[temp_count].count = unique_entity[k].count;
                    temp_count++;
                    is_duplicate = true;
                    break; 
                }
            } 
            if (!is_duplicate) {
                unique_entity[unique_count].entity_type = arr[i][j].entity_type;
                unique_entity[unique_count].entity_id=arr[i][j].entity_id;
                unique_entity[unique_count].count = 1; 
                unique_count++;
            } 
        }
    }
}
printf("unique entities:\n");
for(int i=0;i<unique_count;i++){
    printf("%c - %d\n",unique_entity[i].entity_type, unique_entity[i].count);


    printf("%c-%d the next closest elements are :\n",unique_entity[i].entity_type,unique_entity[i].entity_id);
    
    for (int j = 0; j < temp_count; j++) {
    if(temp[j].entity_type==unique_entity[i].entity_type){
    printf(" %c-%d,\n",temp[j].entity_type, temp[j].entity_id);
}
}
}
}

    

