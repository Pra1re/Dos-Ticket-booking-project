#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // windows api

#define BAR_WIDTH 80  // loading bar length
/*console screen buffer info struct template

typedef struct _CONSOLE_SCREEN_BUFFER_INFO{

    COORD dwSize;              // Size of the screen buffer (columns, rows)
    COORD dwCursorPosition;    // Current cursor position (x, y)
    WORD wAttributes;          // Text attributes (colors, intensity, etc.)
    SMALL_RECT srWindow;       // The window size in the buffer
    COORD dwMaximumWindowSize; // Max possible window size based on buffer

} CONSOLE_SCREEN_BUFFER_INFO;
*/

//compared to a normal struct
/*
typedef struct templatestruct {
    int age;
    char character;


} example;

example x;

*/

int get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi; // a build in structure that stores console info
                                    //like width and height and our variable name is csbi
    int width = 80;                // default width
    //HANDLE
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)){
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    return width;
}
void set_color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Function to print text at the center of the console window
void print_centered(const char *text) {
    int screen_width = get_console_width();
    int padding = (screen_width - strlen(text)) / 2;
    printf("%*s%s\n", padding, "", text);
}
void print_options(const char *text) {
    int screen_width = get_console_width();
    int padding = (screen_width - 7) / 2;
    padding-=13;

    printf("%*s%s\n", padding, "", text);
}

//my commit
//2nd commit test

// function to display a centered loading bar
void show_loading_bar() {
    int screen_width = get_console_width();
    int padding = (screen_width - BAR_WIDTH) / 2;

    print_centered("Loading...");
    printf("\n%*s[", padding, "");

    for (int i = 0; i < BAR_WIDTH; i++) {
        printf(".");
        fflush(stdout);
        Sleep(50);  // speed of the loading effect
    }

    printf("]\n");
    Sleep(500);  // short delay before clearing screen
}

int main() {
    int exitcheck;

    system("cls");  // clears screen after loading bar loads

    // welcome screen
    set_color(10);
    printf("\n\n");
    print_centered("___________");
    print_centered("|_' '_'__'|");
    print_centered("|_' '_'__'|");
    print_centered("====================================================");
    print_centered("================================================");
    print_centered("|      WELCOME TO TICKET BOOKING SYSTEM        |");
    print_centered("================================================");
    print_centered("====================================================");
    printf("\n");

    // show loading bar

    show_loading_bar(); //later dont forget to uncomment
    set_color(7);
      // clear console after loading completes
 /*      ____  _____  _____  _    _ _______ ______
  / __ \|  __ \|  __ \| |  | |__   __|  ____|
 | |  | | |__) | |__) | |  | |  | |  | |__
 | |  | |  _  /|  _  /| |  | |  | |  |  __|
 | |__| | | \ \| | \ \| |__| |  | |  | |____
  \____/|_|  \_\_|  \_\\____/   |_|  |______|
  ------------------------------------------
  |  Explore • Book • Travel • Enjoy!       |
  ------------------------------------------
*/
do{
        system("cls");
    printf("\n\n\n");
    print_centered("----------------------------------");

    print_centered("|  Select a Travelling method :  |");
    print_centered("----------------------------------");
    print_options("|  1.Bus                         |");

    print_options("|  2.Train                       |");
    print_options("|  3.Plane                       |");
    print_centered("__________________________________");
    printf("\n\n");

    int options;
    do{
    printf("Please select a Travelling method: ");
    scanf("%d",&options);
    if(options>3 || options<1){
        print_centered("Please enter a valid option!!");
    }
    }
    while(options>3 || options<1);


//---------------------------bus-----------------------------

    if(options==1){



        print_centered("U have selected bus");
        Sleep(500);
        system("cls");
        //bus option goes here
        printf("\n\n\n");
    print_centered("----------------------------------");

    print_centered("|  Select a Boarding point :     |");
    char boarding[100][100]={"Uttara","Khilkhet","Mohakhali","Saydabad","Guslistan","Sadarghat"};
    print_centered("----------------------------------");
    for(int i=0;i<6;i++){
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
    do{
    printf("Please select a boarding point: ");
    scanf("%d",&boardingoption);
    if(boardingoption>6 || boardingoption<1){
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
    char destination[100][100]={"Chittagong","Cox's Bazar","Khulna","Faridpur","Barishal"};
    print_centered("----------------------------------");
    for(int i=0;i<5;i++){
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
    do{
    printf("Please select a Destination Point: ");
    scanf("%d",&destoption);
    if(destoption>5 || destoption<1){
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

while (fgets(line, sizeof(line), bus)) {
    // Check if the line starts with x
    if (strncmp(line, queryforbus, strlen(queryforbus)) == 0){
        char *route = strtok(line, "$");
        char *bus_name = strtok(NULL, "$");
        char *price = strtok(NULL, "$");
        strcpy(foundbus[busnumbers-1],bus_name);

        // remove newline from price if it exists
        if (price[strlen(price) - 1] == '\n') {
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

    do{
    printf("Please select a Bus number: ");
    scanf("%d",&busnumberoptions);
    if(busnumberoptions>busnumbers-1 || busnumberoptions<1){
        print_centered("Please enter a valid option!!");
    }
    }
    while(busnumberoptions>busnumbers-1 || busnumberoptions<1);


//read from seat.txt


FILE *seat = fopen("seat.txt", "r");
char seatline[1000];
char storebus[1000];

char foundseat[1000];
while (fgets(seatline, sizeof(seatline), seat)) {
    // Check if the line starts with x
    if (strncmp(seatline, foundbus[busnumberoptions-1], strlen(foundbus[busnumberoptions-1])) == 0) {
        strcpy(storebus,seatline);//stores the whole line
        char *bus_names = strtok(seatline, "$");
        char *bus_price = strtok(NULL, "$");
        char *seats = strtok(NULL, "$");



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
for (int j=0;j<ns;j+=2) {
        // Print seat number

        // Print 'X' in red and 'O' in white
        if(j<9){


        if (foundseat[j] == '1') {


        printf("--------------------------------------------------\n");
        printf("%-1d. \033[31m%-20c\033[0m |",j+1,'X'); // red X
        if((j+1)<ns){

                if(j+1<9){

                if (foundseat[j+1] == '1') {
                printf("%-1d. \033[31m%-20c\033[0m |\n",j+2,'X'); // red X

                }
        else{
                printf("%-1d. \033[32m%-20c\033[0m |\n",j+2,'O'); // green O


        }
                }
                else{
                        if (foundseat[j+1] == '1') {
                printf("%-1d. \033[31m%-19c\033[0m |\n",j+2,'X'); // red X

                }
        else{
                printf("%-1d. \033[32m%c\033[0m |\n",j+2,'O'); // green O


        }





                }



        }


        } else {
            printf("--------------------------------------------------\n");
            printf("%-1d. \033[32m%-20c\033[0m |",j+1,'O'); // green O
            if((j+1)<ns){
                if (foundseat[j+1] == '1') {
                printf("%-1d. \033[31m%-20c\033[0m |\n",j+2,'X'); // red X

                }
        else{
                printf("%-1d. \033[32m%-20c\033[0m |\n",j+2,'O'); // green O


        }

        }
        }

        }
     //-------------------------------------------------------


else{
    if (foundseat[j] == '1') {


        printf("---------------------------------------------------\n");
        printf("%-1d. \033[31m%-19c\033[0m |",j+1,'X'); // red X
        if((j+1)<ns){
                if (foundseat[j+1] == '1') {
                printf("%-1d. \033[31m%-19c\033[0m |\n",j+2,'X'); // red X

                }
        else{
                printf("|%-1d. \033[32m%-19c\033[0m |\n",j+2,'O'); // green O


        }

        }


        } else {
            printf("---------------------------------------------------\n");
            printf("%-1d. \033[32m%-19c\033[0m |",j+1,'O'); // green O
            if((j+1)<ns){
                if (foundseat[j+1] == '1') {
                printf("%-1d. \033[31m%-19c\033[0m |\n",j+2,'X'); // red X

                }
        else{
                printf("%-1d. \033[32m%-19c\033[0m |\n",j+2,'O'); // green O


        }

        }
        }








}











    }
printf("\n---------------------------------------------------\n");
  printf("\n\n");
int available=0;
for(int i=0;i<ns;i++){
    if(foundseat[i]=='0'){
        available++;
    }
}
if(available>0){
    int seatcheck;


    do{
    printf("please select a seat: ");
    scanf("%d",&seatcheck);
    if(seatcheck>ns || seatcheck<1){
        printf("Please select a valid option!!\n");
    }
    else if(foundseat[seatcheck-1]=='1'){
        printf("This seat is already booked,pls select another seat\n");
    }
}
while(seatcheck>ns || seatcheck<1 || foundseat[seatcheck-1]=='1');


///--------------printing loop------------------

///changing phase based on ticket selection



printf("\n");
foundseat[seatcheck-1]='1';





///changing phase based on ticket selection

///---------------------seat booking----------------

///found seat = 101001111101001011111
///storebus = Baler-bus$100tk$101001111101001011111

seat = fopen("seat.txt", "r");
FILE *temp=fopen("temp.txt","w");
char line2[500];

while (fgets(line2, sizeof(line2), seat)){
    if (strcmp(storebus, line2) == 0) {
            char *bus_name = strtok(line2, "$");
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
            fprintf(temp, "%s", line2);
        }





}




fclose(seat);
fclose(temp);

remove("seat.txt");
rename("temp.txt", "seat.txt") ;
system("cls");
printf("\n\n\n\n\n\n\n\n\n");
print_centered("Seat booking successful.....");
Sleep(1500);
system("cls");

}
else{
        system("cls");
printf("\n\n\n\n\n\n");
    print_centered("No seat available currently,Please try again later.....");
    Sleep(1500);
}





///---------------------seat booking----------------











    printf("\n");














    }
//------------------------------train-----------------------------------------
    else if(options==2){
          //rafsan am working from here


        print_centered("U have selected Train");
    }
//--------------------------------plane---------------------------------------
    else if(options==3){
        print_centered("U have selected Plane");
    }



















    //go again
//system("cls");


   printf("\n\n\n");
    print_centered("-------------------------------");

    print_centered("|  Select an Option :         |");
    print_centered("-------------------------------");
    print_centered("|  1.Home                     |");

    print_centered("|  2.Exit                     |");
    print_centered("_______________________________");
    printf("\n\n");


    do{
    printf("Please select an Option: ");
    scanf("%d",&exitcheck);
    if(exitcheck>2 || exitcheck<1){
        print_centered("Please enter a valid option!!");
    }
    }
    while(exitcheck>2 || exitcheck<1);





}
   while(exitcheck==1);


getchar();

    return 0;
}
