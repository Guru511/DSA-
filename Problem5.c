#include<stdio.h>
struct arrakies{
    char harvester_name[50];
    char harvest_location[50];
    int spice_amount;
};
void display(struct arrakies  harvest_record[]){
    for(int i=0;i<3;i++){
        printf("harvest record %d : \n",i+1);
        printf("\n harvesters name : %s ",harvest_record[i].harvester_name);
        printf("\n harvest location : %s ",harvest_record[i].harvest_location);
        printf("\n spice amount : %d \n",harvest_record[i].spice_amount);
    }
}
int main(){
    struct arrakies harvest_record[5];
    int i;
    for (i=0;i<3;i++){
        printf("enter the records %d\n",i+1);
        printf("enter harvester name :\n");
        fgets(harvest_record[i].harvester_name,sizeof(harvest_record[i].harvester_name),stdin);
        printf("enter the harvest loacation :\n");
        fgets(harvest_record[i].harvest_location,sizeof(harvest_record[i].harvest_location),stdin);
        printf("enter the spice amount :\n");
        scanf("%d",&harvest_record[i].spice_amount);
        getchar();
        
       

    }
    display(harvest_record);
    return 0;

}



// Harvester Name	Harvest Location	Spice Amount 
// Stilgar	Sietch Tabr	500
// Kynes	Deep Desert	700
// Paul Atreides	Hagga Basin	1000
// Gurney Halleck	Cielago South	650
// Chani	False Wall East	800
// Duncan Idaho	The Great Flat	900
// Rabban	Arrakeen Outskirts	450
// Leto Atreides II	Imperial Basin	1200
// Feyd-Rautha	Shield Wall	750
// The Spacing Guild	Rock Outcrop 9	1300