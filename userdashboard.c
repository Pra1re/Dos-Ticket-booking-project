#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<stdbool.h>
 void userdash(){
     system("cls");
 printf("\n\n\n");
    print_centered("----------------------------------");

    print_centered("|  Select an option:             |");
    print_centered("----------------------------------");
    print_options("|  1.Show balance                |");
    print_options("|  2.Recharge                    |");

    print_options("|  3.Application for Card        |");
    print_centered("__________________________________");
    printf("\n\n");
    int rechcard;
    do{
    printf("Please select an option from above: ");
    scanf("%d",&rechcard);
    if(rechcard>3 || rechcard<1){
        print_centered("Please enter a valid option!!");
    }
    }
    while(rechcard>3 || rechcard<1);
    if(rechcard==1){
        ///-------------------------show the balance------------------------------------

         char id[100];
    char pin[100];
    printf("Enter card id: ");
    scanf("%s",&id);
    printf("Enter pin:     ");
    scanf("%s",&pin);
    bool notexists=true;

        FILE *balance=fopen("creditcard.txt","r");
        char line[100];
        while(fgets(line,sizeof(line),balance)){

                char *fetchedid=strtok(line,"$");
                char *fetchedpin=strtok(NULL,"$");
                char *fetchedstatus=strtok(NULL,"$");
                char *fetchedbalance=strtok(NULL,"$");
                if (fetchedbalance[strlen(fetchedbalance) - 1] == '\n') {
                fetchedbalance[strlen(fetchedbalance) - 1] = '\0';
        }
        if(strcmp(fetchedid,id)==0 && strcmp(fetchedpin,pin)==0 && strcmp(fetchedstatus,"1")==0){
            notexists=false;

            printf("Your current balance is: %s ",fetchedbalance);
            break;

        }





        }

fclose(balance);
if(notexists){

        system("cls");
printf("\n\n\n\n\n\n\n\n\n\n");
    print_centered("Your card is not activate yet please contact the authority....");
    Sleep(4000);
    system("cls");
}



    }

  else if(rechcard==2){
    ///----------------user wants to recharge-------------------------------------------

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
///credit card details matched can recharge now
/*int num = 123;
    char str[20];  // Ensure the buffer is large enough
    sprintf(str, "%d", num);
//----------------------------
    char str[] = "456";
    int num = atoi(str);

    */


int r;
do{
printf("Enter recharge amount: ");
scanf("%d",&r);
if(r<=0){
    printf("Please enter a valid recharge amount!!\n");
}
}while(r<=0);

int newbalance=atoi(balanceincard)+r;
char nbalanceforfile[100]="";
sprintf(nbalanceforfile, "%d", newbalance);

FILE *temp=fopen("temp.txt","w");
creditcard=fopen("creditcard.txt","r");
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

}else{
    printf("Credit card details didnt match.......");
    Sleep(2000);
    system("cls");

}



system("cls");

   //-----------------------------------------------------------------------------------
  }
  else{
    ///------------------user wants to apply for cards-------------------------------
    bool valid=true;
    char id[100];
    char pin[100];
    do{
    valid=true;

    printf("Enter desired id: ");
    scanf("%s",id);
    if(id[strlen(id)-1] =='\n'){
        id[strlen(id)-1]=='\0';
    }
    printf("Enter a pin: ");
    scanf("%s",pin);
if(pin[strlen(pin)-1] =='\n'){
        pin[strlen(pin)-1]=='\0';
    }
    FILE *card=fopen("creditcard.txt","r");

    char line[100];
    while(fgets(line,sizeof(line),card)){

        char *fetchedid=strtok(line,"$");
        if(strcmp(fetchedid,id)==0){
                printf("this id already exists please try a different one.....\n");
            valid=false;
        }

    }


fclose(card);

    }while(valid==false);



FILE *card=fopen("creditcard.txt","a");

char tempcat[1000] = "";
            strcat(tempcat, id);
            strcat(tempcat, "$");
            strcat(tempcat, pin);
            strcat(tempcat, "$");
            strcat(tempcat, "0");
            strcat(tempcat, "$");
            strcat(tempcat, "0");
            fprintf(card, "%s\n", tempcat);
            fclose(card);

    //----------------------------------------------------------------------------------
    system("cls");
  }



 }




