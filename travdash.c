#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<stdbool.h>
int travordash(){
printf("\n\n\n");
    print_centered("----------------------------------");

    print_centered("|  Select an option:             |");
    print_centered("----------------------------------");
    print_options("|  1.User Management             |");

    print_options("|  2.Travel                      |");
    print_options("|  3.Logout                      |");
    print_centered("__________________________________");
    printf("\n\n");

    int dashtrav;
    do{
    printf("Please select an option: ");
    scanf("%d",&dashtrav);
    if(dashtrav>2 || dashtrav<1){
        print_centered("Please enter a valid option!!");
    }
    }
    while(dashtrav>2 || dashtrav<1);
    system("cls");
    return dashtrav;
    }
