#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define BAR_WIDTH 80
int get_console_width()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi; // a build in structure that stores console info
    //like width and height and our variable name is csbi
    int width = 80;                // default width
    //HANDLE
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    return width;
}

void print_centered(const char *text)
{
    int screen_width = get_console_width();
    int padding = (screen_width - strlen(text)) / 2;
    printf("%*s%s\n", padding, "", text);
}



void show_loading_bar()
{
    int screen_width = get_console_width();
    int padding = (screen_width - BAR_WIDTH) / 2;

    print_centered("Loading...");
    printf("\n%*s[", padding, "");

    for (int i = 0; i < BAR_WIDTH; i++)
    {
        printf(".");
        fflush(stdout);
        Sleep(50);  // speed of the loading effect
    }

    printf("]\n");
    Sleep(500);  // short delay before clearing screen
}
void set_color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void print_options(const char *text)
{
    int screen_width = get_console_width();
    int padding = (screen_width - 7) / 2;
    padding-=13;

    printf("%*s%s\n", padding, "", text);
}




