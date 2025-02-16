#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include<stdbool.h>
void moneydeduct(char *id,char *nbalanceforfile){


FILE *temp=fopen("temp.txt","w");
FILE *creditcard=fopen("creditcard.txt","r");
char line2[100];
while(fgets(line2,sizeof(line2),creditcard)){

        char *fetchedid=strtok(line2,"$");
        char *fetchedpin=strtok(NULL,"$");
        char *fetchedstatus=strtok(NULL,"$");
        char *fetchedbalance=strtok(NULL,"$");
    if (strcmp(fetchedid, id) == 0) {
            char tempcat[1000] = "";
            strcat(tempcat, fetchedid);
            strcat(tempcat, "$");
            strcat(tempcat, fetchedpin);
            strcat(tempcat, "$");
            strcat(tempcat, fetchedstatus);
            strcat(tempcat, "$");
            strcat(tempcat, nbalanceforfile);

            fprintf(temp, "%s\n", tempcat);
        } else {
            char tempcat[1000] = "";
            strcat(tempcat, fetchedid);
            strcat(tempcat, "$");
            strcat(tempcat, fetchedpin);
            strcat(tempcat, "$");
            strcat(tempcat, fetchedstatus);
            strcat(tempcat, "$");
            strcat(tempcat, fetchedbalance);
            fprintf(temp, "%s", tempcat);
        }






}
fclose(temp);
fclose(creditcard);

remove("creditcard.txt");
rename("temp.txt","creditcard.txt");
}
