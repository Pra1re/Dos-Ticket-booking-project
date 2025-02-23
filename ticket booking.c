#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // windows api
#include "library.h"
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



// Function to print text at the center of the console window


//my commit
//2nd commit test

// function to display a centered loading bar

int main()
{
    int exitcheck;

    system("cls");  // clears screen after loading bar loads

    // welcome screen
    set_color(10);
    welcome_screen();

    // show loading bar

    show_loading_bar(); //later dont forget to uncomment
    set_color(7);
    system("cls");
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
    do
    {
        int dashtrav=travordash();

        if(dashtrav==1){
                userdash();

        }
        else{

///-------------------------showing travel options----------------------
        int options =traveloption();

///---------------------------bus-----------------------------

        if(options==1)
        {
         bus();

        }
//------------------------------train-----------------------------------------
        else if(options==2)
        {
            //rafsan am working from here


            alltrain();
        }
//--------------------------------plane---------------------------------------
        else if(options==3)
        {
            print_centered("U have selected Plane");
        }

        }
//go again
//system("cls");
        exitcheck=homexit();


    }
    while(exitcheck==1);


    getchar();

    return 0;
}
