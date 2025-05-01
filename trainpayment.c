#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#include "library.h"

bool trainpayment(char *seatprice){
///take card id and pin input if its valid proceed else show card not valid cant book seat
    char id[100];
    char pin[100];
    printf("Enter card id: ");
    scanf("%s",id);
    printf("Enter pin:     ");
    scanf("%s",pin);

///look for the id and pin in  txt file


FILE *creditcard=fopen("creditcard.txt","r");

char line[100]="";
bool match=false;///dont forget to clear on logout very important
char balanceincard[100]="";
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
if(match==true){
///credit card details matched can book seat now
/*int num = 123;
    char str[20];  // Ensure the buffer is large enough
    sprintf(str, "%d", num);
//----------------------------
    char str[] = "456";
    int num = atoi(str);

    */

int newbalance=atoi(balanceincard)-atoi(seatprice);
if(newbalance>=0){
///-------balance deduction "if" statement starts-------------------
char nbalanceforfile[100]="";
sprintf(nbalanceforfile, "%d", newbalance);

///-------------deduct money from card---------------------------------
moneydeduct(id,nbalanceforfile);
///--------------------------------------------------------------------


///------------------seat marking as visited---------------------------
return true;

///--------------------------------------------------------------------


///-------balance deduction "if" statement ends-------------------------
}
else{
        system("cls");
printf("\n\n\n\n\n\n\n\n\n\n");
    print_centered("insufficient balance Please recharge");
    Sleep(4000);
    system("cls");
}


}else{
    system("cls");
printf("\n\n\n\n\n\n\n\n\n\n");
    print_centered("Credit card details didnt match");
    Sleep(3000);
    system("cls");

}


return false;

}
