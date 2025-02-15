
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



int traveloption(){

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
        do
        {
            printf("Please select a Travelling method: ");
            scanf("%d",&options);
            if(options>3 || options<1)
            {
                print_centered("Please enter a valid option!!");
            }
        }
        while(options>3 || options<1);

 return options;

}
