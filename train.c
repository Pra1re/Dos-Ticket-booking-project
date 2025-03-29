#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "library.h"
///markasvisited = seatmarkasvisited
///seatdesign = designallseat
void seatmarkasvisited(char *foundseat,int selected_seat,char *seat_line)
{
    printf("\n");
    foundseat[selected_seat-1]='1';


    FILE *seat = fopen("compartments.txt", "r");
    FILE *temp=fopen("temp.txt","w");
    char line3[500];

    while (fgets(line3, sizeof(line3), seat))
    {
        if (strcmp(seat_line, line3) == 0)
        {

            char *bus_name = strtok(line3, "$");
            char *price = strtok(NULL, "$");
            char *availability = strtok(NULL, "$");


            char tempcat[1000] = "";
            strcat(tempcat, bus_name);
            strcat(tempcat, "$");
            strcat(tempcat, price);
            strcat(tempcat, "$");
            strcat(tempcat, foundseat);

            fprintf(temp, "%s", tempcat);
        }
        else
        {
            fprintf(temp, "%s", line3);
        }

    }

    fclose(seat);
    fclose(temp);

    remove("compartments.txt");
    rename("temp.txt", "compartments.txt");
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
    print_centered("Seat booking successful.....");
    Sleep(4000);
    system("cls");

}


// function for printing seats

void designallseat(int ns,char *foundseat)
{

    for (int j=0; j<ns; j+=4)
    {
        if(j<=8)
        {
            if((j+3)<ns)
            {
                printf("                        ---------------------                         ---------------------\n");
                if(j<8)
                {

                    (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));
                    (foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m    |                         ",j+2):printf("|    \033[32m%d\033[0m    |                         ",j+2));
                    (foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m    ",j+3):printf("|    \033[32m%d\033[0m    ",j+3));
                    (foundseat[j+3]=='1'?printf("|    \033[31m%d\033[0m    |\n",j+4):printf("|    \033[32m%d\033[0m    |\n",j+4));
                }
                else
                {
                    (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));
                    (foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |                         ",j+2):printf("|    \033[32m%d\033[0m   |                         ",j+2));
                    (foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m   ",j+3):printf("|    \033[32m%d\033[0m   ",j+3));
                    (foundseat[j+3]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+4):printf("|    \033[32m%d\033[0m   |\n",j+4));

                }
            }
            else if((j+2)<ns)
            {
                printf("                        ---------------------                          -----------\n");

                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));
                (foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m    |                         ",j+2):printf("|    \033[32m%d\033[0m    |                         ",j+2));
                (foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m    |\n",j+3):printf("|    \033[32m%d\033[0m    |\n",j+3));


            }
            else if((j+1)<ns)
            {

                printf("                        ---------------------\n");
                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));
                (foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m    |\n",j+2):printf("|    \033[32m%d\033[0m    |\n",j+2));

            }
            else
            {
                printf("                        -----------\n");

                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    |\n",j+1):printf("                        |    \033[32m%d\033[0m    |\n",j+1));


            }
        }
        else
        {

            if((j+3)<ns)
            {
                printf("                        ---------------------                         ---------------------\n");

                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   ",j+1):printf("                        |    \033[32m%d\033[0m   ",j+1));
                (foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |                         ",j+2):printf("|    \033[32m%d\033[0m   |                         ",j+2));
                (foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m   ",j+3):printf("|    \033[32m%d\033[0m   ",j+3));
                (foundseat[j+3]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+4):printf("|    \033[32m%d\033[0m   |\n",j+4));

            }
            else if((j+2)<ns)
            {
                printf("                        ---------------------                          -----------\n");

                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   ",j+1):printf("                        |    \033[32m%d\033[0m   ",j+1));
                (foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |                         ",j+2):printf("|    \033[32m%d\033[0m   |                         ",j+2));
                (foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+3):printf("|    \033[32m%d\033[0m   |\n",j+3));


            }
            else if((j+1)<ns)
            {

                printf("                        ---------------------\n");
                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   ",j+1):printf("                        |    \033[32m%d\033[0m   ",j+1));
                (foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+2):printf("|    \033[32m%d\033[0m   |\n",j+2));

            }
            else
            {
                printf("                        -----------\n");

                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   |\n",j+1):printf("                        |    \033[32m%d\033[0m   |\n",j+1));

            }
        }
    }
}






void alltrain(){

    system("cls");  // clear console after loading completes
    set_color(7);
    printf("\n\n\n\n");
    print_centered("-----Welcome to BD train service-----");
    printf("\n\n");



    //selecting from, destination and class type


    print_centered("__________________________");
    print_centered("|         From           |");
    print_centered("|________________________|");
    print_centered("| 1) Dhaka               |");
    print_centered("| 2) Chattagram          |");
    print_centered("| 3) Rajshahi            |");
    print_centered("| 4) Barishal            |");
    print_centered("| 5) Noakhali            |");
    print_centered("| 6) Sylhet              |");
    print_centered("|________________________|");
    printf("\n\n\n\n");

    int str,des;
    do
    {
        printf("Select your starting point : ");
        scanf("%d",&str);
        if(str>6 || str <1)
            print_centered("invalid input!!try again!!!\n");
    }
    while(str>6 || str <1);

    do
    {
        printf("Select your destination point : ");
        scanf("%d",&des);
        if(des==str || des>6 || des <1)
            print_centered("invalid input!!try again!!!\n");
    }
    while(des==str || des>6 || des <1);

    char places[6][100]= {"Dhaka","Chattagram","Rajshahi","Barishal","Noakhali","Sylhet"};
    system("cls");

    strcat(places[str-1],places[des-1]);

    char x[1000];
    strcpy(x,places[str-1]);



    //taking train_names from "train_name.txt" file



    FILE *train = fopen("train_name.txt", "r");
    char line[100];
    char trains[5][100000];
    int flag=0;

    while (fgets(line, sizeof(line), train))
    {
        if (strncmp(line, x, strlen(x)) == 0)
        {
            // Extract values using '$' as a delimiter
            char *destination_name = strtok(line, "$");
            char *train_name = strtok(NULL, "$");
            if (train_name[strlen(train_name) - 1] == '\n')
            {
                train_name[strlen(train_name) - 1] = '\0';
            }

            strcpy(trains[flag],train_name);//storing train names
            flag++;
        }
    }

    fclose(train);


    //show trains and choose train




    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    print_centered("------Available Trains------");
    print_centered("____________________________");

    for(int i=0; i<flag; i++)
    {
        char formatted[100];
        snprintf(formatted, sizeof(formatted), "| %d) %-21s |", i + 1, trains[i]);
        print_centered(formatted);
    }
    print_centered("|__________________________|");
    printf("\n\n\n\n\n\n\n\n");

    int my_train;
    do
    {
        printf("Select a train : ");
        scanf("%d",&my_train);
        if(my_train > flag || my_train < 1)
            print_centered("invalid input!! Select proper Train!!!\n");
    }
    while(my_train > flag || my_train < 1);
    system("cls");





    //Bring class ans prices from ticketprize file



    FILE *clss = fopen("ticketprise.txt", "r");
    char lin[100];
    char classes[100][100];
    char prices[100][100];
    int fla = 0;
    printf("\n\n\n");
    print_centered("!!!!!!----Select class as you can----!!!!!!\n\n\n");
    print_centered("_________________________________________________");
    print_centered("|         Class          |         Price         |");
    print_centered("|________________________|_______________________|");

    while (fgets(lin, sizeof(lin), clss))
    {
        if (strncmp(lin, trains[my_train-1], strlen(trains[my_train-1])) == 0)
        {

            // Extract values using '$' as a delimiter
            char * t = strtok(lin,"$");
            char *class_name = strtok(NULL, "$");
            char *ticket_price = strtok(NULL, "$");

            strcpy(classes[fla],class_name);
            strcpy(prices[fla],ticket_price);

            if (ticket_price[strlen(ticket_price) - 1] == '\n')
            {
                ticket_price[strlen(ticket_price) - 1] = '\0';
            }

            printf("\t\t\t\t   |%d.%-22s", fla + 1, classes[fla]);
            printf("|%22s |\n", ticket_price);
            fla++;
        }
    }

    fclose(clss);

    print_centered("|________________________|_______________________|");
    printf("\n\n\n\n");



    //input class;

    int my_class;
    do
    {
        printf("Choose a class for travelling : ");
        scanf("%d",&my_class);
        if(my_class > 5 || my_class < 1)
            print_centered("invalid input!! Select proper class!!!\n");
    }
    while(my_class > 5 || my_class < 1);

    system("cls");

    char train_class[100];
    strcat(trains[my_train-1],classes[my_class-1]);
    strcpy(train_class,trains[my_train-1]);



    // Sellect and print compertment and searts from file--------------------



    FILE *cmprt = fopen("compartments.txt", "r");
    char cmprt_line[1000];
    char cmprts[5][100];
    char seat_line[100][1000];
    char found_seats[1000][1000];
    int c_flag = 0;

    printf("\n\n\n");
    print_centered("!!!!!!----Available seats in compartments----!!!!!!\n\n\n");
    print_centered("______________________________________________________________");
    print_centered("|    Available Compartment    |        Available seats       |");
    print_centered("|_____________________________|______________________________|");

    char cmprt_tmp[1000];

    while (fgets(cmprt_line, sizeof(cmprt_line), cmprt))
    {
        if (strncmp(cmprt_line,train_class,strlen(train_class)) == 0)
        {

            strcpy(cmprt_tmp,cmprt_line);

            char * t_c = strtok(cmprt_line,"$");
            char *cmprt_name = strtok(NULL, "$");
            char *seats = strtok(NULL, "$");

            int tmp = (int)cmprt_name[0] - 'A';

            strcpy(seat_line[tmp],cmprt_tmp);
            strcpy(cmprts[c_flag],cmprt_name);
            strcpy(found_seats[tmp],seats);


            // _____________________ printing seats and compartment nam______________________

            printf("\t\t\t     |%d.%-27s", c_flag + 1, cmprt_name);

            int papa =0;
            for(int i=0; i<strlen(found_seats[tmp]); i++)
            {
                if(found_seats[tmp][i] == '0')
                    papa++;
            }
            printf("|%29d |\n", papa);
            c_flag++;

        }
    }

    fclose(cmprt);

    print_centered("|_____________________________|______________________________|");
    printf("\n\n\n\n");



    // ___________ taking input for compartment to print seats _________

    int my_cmprt;
    do
    {
        printf("Choose a compartment : ");
        scanf("%d",&my_cmprt);
        if(my_cmprt > c_flag || my_cmprt < 1)
            print_centered("invalid input!! Select proper class!!!\n");
    }
    while(my_cmprt > c_flag || my_cmprt < 1);



    system("cls");

    char stp = cmprts[my_cmprt-1][0];
    int stmp = stp - 'A';
    int total_seats = strlen(found_seats[stmp])-1;





    // printing seats with designallseat function


    printf("\n\n");
    print_centered("______ sellect seats from bellow ______");
    printf("\n\n");

    designallseat(total_seats, found_seats[stmp]);


    int my_seat;
    do
    {
        printf("Choose a seat for relax travelling : ");
        scanf("%d",&my_seat);
        if(my_seat > total_seats || my_seat < 1)
            print_centered("invalid input!! Select proper seat!!!\n");
        else if(found_seats[stmp][my_seat-1]=='1')
            print_centered("This seat is already booked!!! Try another one \n");
    }
    while(my_seat > total_seats || my_seat < 1 || found_seats[stmp][my_seat-1]=='1');

    printf("\n\n\n");

    seatmarkasvisited(found_seats[stmp], my_seat, seat_line[stmp]);


}
