#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // windows api

#define BAR_WIDTH 80  // loading bar length

int get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi; // a build in structure that stores console info
                                    //like width and height and our variable name is csbi
    int width = 80;  // default width

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    return width;
}
void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Function to print text at the center of the console window
void print_centered(const char *text) {
    int screen_width = get_console_width();
    int padding = (screen_width - strlen(text)) / 2;
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
    show_loading_bar();
    set_color(7);

    system("cls");  // clear console after loading completes

    print_centered("Welcome to dracarys!!");

    return 0;
}
