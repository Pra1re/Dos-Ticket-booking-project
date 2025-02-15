#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>




int homexit(){
    int exitcheck;
printf("\n\n\n");
        print_centered("-------------------------------");

        print_centered("|  Select an Option :         |");
        print_centered("-------------------------------");
        print_centered("|  1.Home                     |");
        print_centered("|  2.Exit                     |");
        print_centered("_______________________________");
        printf("\n\n");


        do
        {
            printf("Please select an Option: ");
            scanf("%d",&exitcheck);
            if(exitcheck>2 || exitcheck<1)
            {
                print_centered("Please enter a valid option!!");
            }
        }
        while(exitcheck>2 || exitcheck<1);
system("cls");
return exitcheck;
}
