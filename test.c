#include<stdio.h>
#include<math.h>
#include <string.h>
int main(){
 char x[50] = "Yaaay_bus!!";
    FILE *bus = fopen("seat.txt", "r");
    char line[1000];
    char storebus[1000];
char desiredbus[1000];

    while (fgets(line, sizeof(line), bus)){
        // Check if the line starts with x
        printf("%s\n",line);
        if (strncmp(line, x, strlen(x)) == 0) {
                strcpy(storebus,line);
            // Extract values using '$' as a delimiter
            char *route = strtok(line, "$");
            char *bus_name = strtok(NULL, "$");
            char *price = strtok(NULL, "$");

            strcpy(desiredbus,price);

                printf("Route: %s\n", route);
                printf("Bus Name: %s\n", bus_name);
                printf("Price: %s\n", price);

        }
    }




printf("%s\n",desiredbus);


for(int i=0;i<strlen(desiredbus);i++){
    if(desiredbus[i]=='1'){
    printf("%d) %c\n",i+1,'X');
    }
    else{
        printf("%d) %c\n",i+1,'O');
    }

}
int available=0;
for(int i=0;i<strlen(desiredbus);i++){
        printf("%c ",desiredbus[i]);
    if(desiredbus[i]=='0'){
        available++;
    }
}
printf("\n");
int sel;
if(available>0){
do{
    printf("please select a seat: ");
    scanf("%d",&sel);
    if(sel>strlen(desiredbus) || sel<1){
        printf("Please select a valid option!!\n");
    }
}
while(sel>strlen(desiredbus) || sel<1);
desiredbus[sel-1]='1';
printf("desiredbus after modification = ");
for(int i=0;i<strlen(desiredbus);i++){
    printf("%c ",desiredbus[i]);
}
printf("\n");
fclose(bus);
bus = fopen("seat.txt", "r");
FILE *temp=fopen("temp.txt","w");
char line2[500];



while (fgets(line2, sizeof(line2), bus)){





    if (strcmp(storebus, line2) == 0) {
         printf("storebus is = %s\n",storebus);
        printf("line is = %s\n",line2);
            char *bus_name = strtok(line2, "$");
            char *price = strtok(NULL, "$");
            char *availability = strtok(NULL, "$");
            printf("bus name = %s || bus price is = %s  || bus availability = %s\n",bus_name,price,availability);


            char tempcat[1000] = "";
            strcat(tempcat, bus_name);
            strcat(tempcat, "$");
            strcat(tempcat, price);
            strcat(tempcat, "$");
            strcat(tempcat, desiredbus);
            printf("string after concat = %s\n",tempcat);

            fprintf(temp, "%s", tempcat);
        } else {
            fprintf(temp, "%s", line2);
        }





}




fclose(bus);
fclose(temp);

remove("seat.txt");
rename("temp.txt", "seat.txt") ;




}
else{
    printf("all seats are currently booked pls try again later...\n");
}




/*
    char destination[100][100]={"Chittagong","Cox's Bazar","Khulna","Faridpur","Barishal"};
    for(int i=0;i<5;i++){

        printf("%s\n",destination[i]);

    }
*/

return 0;}
