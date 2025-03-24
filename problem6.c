#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[50];
    char house[50];
};
void sort(struct node s[],int n){
    
    struct node temp;
    for(int i=0;i<n-1;i++){
       
       for (int j=0;j<n-1-i;j++){
        if(strcmp(s[j].name,s[j+1].name)>0){
            temp=s[j];
            s[j] = s[j+1];
            s[j+1]=temp;
            

        }
       }
     
    }
}
int binarysearch(struct node s[], int n,char key[]){
    int l=0, r=n-1, mid;
   
    while(l<=r){
        mid=(l+r)/2;
        
        if(strcmp(key,s[mid].name)==0){
            return mid;
        }else if(strcmp(key,s[mid].name)<0){
            r=mid-1;
        }else{
            l=mid+1;
        }
        

        }
        return-1;
    }


void main(){
    struct node *s;
   int n;

   printf("enter the number of students you want to enter :\n");
   scanf("%d",&n);
   getchar();
  
   s= (struct node*)malloc(n * sizeof(struct node));
   for(int i=0;i<n;i++){
    printf("enter the name %d:\n",i+1);
    // scanf("%s",s[i].name);
    fgets(s[i].name,sizeof(s[i].name),stdin);
    s[i].name[strcspn(s[i].name,"\n")]=0;

    printf("enter the house %d:\n",i+1);
    // scanf("%s",s[i].house);
    fgets(s[i].house,sizeof(s[i].house),stdin);
    s[i].house[strcspn(s[i].house,"\n")]=0;
}
sort(s,n);

char key[50];
printf("enter the name to search : \n");
fgets(key,sizeof(key),stdin);
key[strcspn(key,"\n")]=0;
int result =binarysearch(s,n,key);
if(result==-1){
    printf("%s is not found \n",key);
}else{
    printf("%s house is %s",key,s[result].house);
}
}
// Harry Potter   Gryffindor
// Hermione Granger  Gryffindor
// Draco Malfoy   Slytherin
// Severus Snape  Slytherin
// Luna Lovegood  Ravenclaw