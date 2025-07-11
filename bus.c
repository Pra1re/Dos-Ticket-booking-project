#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include<stdbool.h>

 void bus(){


 print_centered("U have selected bus");
            Sleep(500);
            system("cls");
            //bus option goes here
            printf("\n\n\n");
            print_centered("----------------------------------");

            print_centered("|  Select a Boarding point :     |");
            char boarding[100][100]= {"Uttara","Khilkhet","Mohakhali","Saydabad","Guslistan","Sadarghat"};
            print_centered("----------------------------------");
            for(int i=0; i<6; i++)
            {
                char formatted[100];
                /*
                char queryforbus[100];
                strcpy(queryforbus, boarding[i]);
                printf("successfully copied = %s\n",queryforbus);
                */

                snprintf(formatted, sizeof(formatted), "|  %d.%-26s  |", i + 1, boarding[i]);

                // passing the fully formatted string to print_options
                print_options(formatted);

            }

            print_centered("__________________________________");



//-----------------------------------nested options-----------------------

            printf("\n\n");

            int boardingoption;
            do
            {
                printf("Please select a boarding point: ");
                scanf("%d",&boardingoption);
                if(boardingoption>6 || boardingoption<1)
                {
                    print_centered("Please enter a valid option!!");
                }
            }
            while(boardingoption>6 || boardingoption<1);

            char queryforbus[100];
            strcpy(queryforbus, boarding[boardingoption-1]);
            Sleep(500);
            system("cls");
            printf("Selected %s\n",queryforbus);
//boardingoption holds boardingpoint

//--------------------------------------destination----------------------------------------------


            printf("\n\n\n");
            print_centered("----------------------------------");

            print_centered("| Select a Destination point :   |");
            char destination[100][100]= {"Chittagong","Cox's Bazar","Khulna","Faridpur","Barishal"};
            print_centered("----------------------------------");
            for(int i=0; i<5; i++)
            {
                char formatted[100];
                /*
                char queryforbus[100];
                strcpy(queryforbus, boarding[i]);
                printf("successfully copied = %s\n",queryforbus);
                */

                snprintf(formatted, sizeof(formatted), "|  %d.%-26s  |", i + 1, destination[i]);

                // passing the fully formatted string to print_options
                print_options(formatted);

            }

            print_centered("__________________________________");


            printf("\n\n");

            int destoption;
            do
            {
                printf("Please select a Destination Point: ");
                scanf("%d",&destoption);
                if(destoption>5 || destoption<1)
                {
                    print_centered("Please enter a valid option!!");
                }
            }
            while(destoption>5 || destoption<1);

            strcat(queryforbus,destination[destoption-1]);
//printf("query string = %s",queryforbus);
///now we can look in the text file for xy to show the data in a table
            system("cls");

            FILE *bus = fopen("test.txt", "r");
            char line[100];
            printf("\n\n");
            print_centered("Available Bus");
            print_centered("-------------------\n\n");
            printf("---------------------------------------------------------------\n");
            printf("%-30s | %30s\n", "|Bus Name", "Price|");

            int busnumbers = 1;
            char foundbus[100][100];

            while (fgets(line, sizeof(line), bus))
            {
                // Check if the line starts with x
                if (strncmp(line, queryforbus, strlen(queryforbus)) == 0)
                {
                    char *route = strtok(line, "$");
                    char *bus_name = strtok(NULL, "$");
                    char *price = strtok(NULL, "$");
                    strcpy(foundbus[busnumbers-1],bus_name);

                    // remove newline from price if it exists
                    if (price[strlen(price) - 1] == '\n')
                    {
                        price[strlen(price) - 1] = '\0';
                    }

                    printf("---------------------------------------------------------------\n");
                    printf("|%d.%-28s", busnumbers, bus_name);
                    printf("|%30s|\n", price);
                    busnumbers++;
                }
            }
            printf("---------------------------------------------------------------\n");

            fclose(bus);

            printf("\n\n\n");
            print_centered("---------------------------------------------");

            print_centered("|  Select available ticket from the list :  |");
            print_centered("---------------------------------------------");
            printf("\n\n");
            /*
            for(int i=0;i<busnumbers-1;i++){
                print_options("|  %d.%s                         |",i+1,foundbus);

                 }
                print_centered("__________________________________");
                printf("\n\n");
                */
            int busnumberoptions;

            do
            {
                printf("Please select a Bus number: ");
                scanf("%d",&busnumberoptions);
                if(busnumberoptions>busnumbers-1 || busnumberoptions<1)
                {
                    print_centered("Please enter a valid option!!");
                }
            }
            while(busnumberoptions>busnumbers-1 || busnumberoptions<1);


//read from seat.txt


            FILE *seat = fopen("seat.txt", "r");
            char seatline[1000];
            char storebus[1000];

            char foundseat[1000],seatprice[1000];
            while (fgets(seatline, sizeof(seatline), seat))
            {
                // Check if the line starts with x
                if (strncmp(seatline, foundbus[busnumberoptions-1], strlen(foundbus[busnumberoptions-1])) == 0)
                {
                    strcpy(storebus,seatline);//stores the whole line
                    char *bus_names = strtok(seatline, "$");
                    char *bus_price = strtok(NULL, "$");
                    char *seats = strtok(NULL, "$");
                    strcpy(seatprice,bus_price);



                    // remove newline from price if it exists
                    /* if (seats[strlen(seats) - 1] == '\n') {
                         seats[strlen(seats) - 1] = '\0';
                     }*/
                    strcpy(foundseat,seats);//foundseat just stores the binary string
                    //int seats_per_row = strlen(foundseat[seatnumbers - 1]) / 2;
                    /*for (int j = 0; j < strlen(foundseat[seatnumbers - 1]); j++) {
                    // Print seat number
                    printf("|%-1d - ", j + 1);

                    // Print 'X' in red and 'O' in white
                    if (foundseat[seatnumbers - 1][j] == '1') {
                        printf("\033[31m%c\033[0m | ",'X'); // red X
                    } else {
                        printf("\033[32m%c\033[0m |",'O'); // green O
                    }

                    // New line after half seats for 2-row display
                    if ((j + 1) % 7 == 0) {
                            printf("\n\n");
                    printf("----------------------------------------------------------------------------");
                        printf("\n\n");
                    }
                    }*/



                }
            }

            fclose(seat);
///------------printing loop---------------
            system("cls");
            printf("\n\n\n\n");
            print_centered("Select available seat from below\n\n\n");
            int ns=strlen(foundseat)-1;
            ///-----------------seat design-------------------------------------
            seatdesign(ns,foundseat);
            ///printf("--------------------\n");
            printf("\n\n");
            int available=0;
            for(int i=0; i<ns; i++)
            {
                if(foundseat[i]=='0')
                {
                    available++;
                }
            }
            if(available>0)
            {


                int seatcheck;


                do
                {
                    printf("please select a seat: ");
                    scanf("%d",&seatcheck);
                    if(seatcheck>ns || seatcheck<1)
                    {
                        printf("Please select a valid option!!\n");
                    }
                    else if(foundseat[seatcheck-1]=='1')
                    {
                        printf("This seat is already booked,pls select another seat\n");
                    }
                }
                while(seatcheck>ns || seatcheck<1 || foundseat[seatcheck-1]=='1');


///--------------printing loop------------------
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

markseatvisited(foundseat,seatcheck,storebus);

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





///---------------------------------------------------------------------------------------------
///changing phase based on ticket selection


            }
            else
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n");
                print_centered("No seat available currently,Please try again later.....");
                Sleep(3000);
            }





///---------------------seat booking----------------











            printf("\n");



 }





