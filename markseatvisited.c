#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "library.h"
#include<stdbool.h>
void markseatvisited(char *foundseat,int seatcheck,char *storebus){
printf("\n");
foundseat[seatcheck-1]='1';





///changing phase based on ticket selection

///---------------------seat booking----------------

///found seat = 101001111101001011111
///storebus = Baler-bus$100tk$101001111101001011111

FILE *seat = fopen("seat.txt", "r");
FILE *temp=fopen("temp.txt","w");
char line3[500];

while (fgets(line3, sizeof(line3), seat)){
    if (strcmp(storebus, line3) == 0) {
            char *bus_name = strtok(line3, "$");
            char *price = strtok(NULL, "$");
            char *availability = strtok(NULL, "$");

            //printf("bus name = %s || bus price is = %s  || bus availability = %s\n",bus_name,price,availability);


            char tempcat[1000] = "";
            strcat(tempcat, bus_name);
            strcat(tempcat, "$");
            strcat(tempcat, price);
            strcat(tempcat, "$");
            strcat(tempcat, foundseat);

            fprintf(temp, "%s", tempcat);
        } else {
            fprintf(temp, "%s", line3);
        }





}




fclose(seat);
fclose(temp);

remove("seat.txt");
rename("temp.txt", "seat.txt") ;
system("cls");
printf("\n\n\n\n\n\n\n\n\n");
print_centered("Seat booking successful.....");
Sleep(4000);
system("cls");

}
