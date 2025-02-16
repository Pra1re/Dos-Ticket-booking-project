#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "library.h"
#include<stdbool.h>
bool checkcardforpayment(){

while (fgets(line, sizeof(line), creditcard)){

    char *fetchedid=strtok(line,"$");
    char *fetchedpin=strtok(NULL,"$");
    char *fetchedstatus=strtok(NULL,"$");
    char *fetchedbalance=strtok(NULL,"$");
    strcpy(balanceincard,fetchedbalance);
        if(strcmp(fetchedid,id)==0 && strcmp(fetchedpin,pin)==0 && strcmp(fetchedstatus,"1")==0){
            match=true;
            break;

        }




}
fclose(creditcard);

return match;
}
