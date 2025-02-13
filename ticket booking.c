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
    system("cls");  // clears screen after loading bar loads

    // welcome screen
    set_color(10);
    print_centered("====================================================");
    print_centered("================================================");
    print_centered("|      WELCOME TO TICKET BOOKING SYSTEM        |");
    print_centered("================================================");
    print_centered("====================================================");
    printf("\n");

    // show loading bar
    //show_loading_bar(); //later dont forget to uncomment
    set_color(7);
    system("cls");  // clear console after loading completes


    printf("\n\n\n");
    print_centered("----------------------------------");

    print_centered("|  Select a Travelling method :  |");
    print_centered("----------------------------------");
    print_options("|  1.Bus                         |");
    print_options("|  2.Train                       |");
    print_options("|  3.Plane                       |");
    print_centered("----------------------------------");

    int options;
    do{
    scanf("%d",&options);
    if(options>3){
        print_centered("Please enter a valid option!!");
    }
    }
    while(options>3);
    if(options==1){
        print_centered("U have selected bus");
    }
    else if(options==2){
        print_centered("U have selected Train");
    }
    else if(options==3){
        print_centered("U have selected Plane");
    }








    return 0;
}
