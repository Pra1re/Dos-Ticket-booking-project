#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include<stdbool.h>
void seatdesign(int ns,char *foundseat){

for (int j=0; j<ns; j+=4)
            {
                ///found seat = 101001111101001011111
               ///storebus = Baler-bus$100tk$101001111101001011111

                   /* if((j+4)<ns){

                           printf("--------------------------------------------------\n");
         (foundseat[j]=='1'?printf("|    \033[31mX\033[0m    "):printf("|    \033[32mO\033[0m    "));(foundseat[j+1]=='1'?printf("|    \033[31mX\033[0m    "):printf("|    \033[32mO\033[0m    "));(foundseat[j+2]=='1'?printf("|    \033[31mX\033[0m    "):printf("|    \033[32mO\033[0m    "));(foundseat[j+3]=='1'?printf("|    \033[31mX\033[0m    "):printf("|    \033[32mO\033[0m    "));(foundseat[j+4]=='1'?printf("|    \033[31mX\033[0m    |\n"):printf("|    \033[32mO\033[0m    |\n"));

                    }*/
                    if(j<=8){
                    if((j+3)<ns){
                            printf("                        ---------------------                         ---------------------\n");
                            if(j<8){

         (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));(foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m    |                         ",j+2):printf("|    \033[32m%d\033[0m    |                         ",j+2));(foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m    ",j+3):printf("|    \033[32m%d\033[0m    ",j+3));(foundseat[j+3]=='1'?printf("|    \033[31m%d\033[0m    |\n",j+4):printf("|    \033[32m%d\033[0m    |\n",j+4));
                            }
                            else{
                                (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));(foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |                         ",j+2):printf("|    \033[32m%d\033[0m   |                         ",j+2));(foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m   ",j+3):printf("|    \033[32m%d\033[0m   ",j+3));(foundseat[j+3]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+4):printf("|    \033[32m%d\033[0m   |\n",j+4));

                            }
                    }
                    else if((j+2)<ns){
                        printf("                        ---------------------                          -----------\n");

         (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));(foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m    |                         ",j+2):printf("|    \033[32m%d\033[0m    |                         ",j+2));(foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m    |\n",j+3):printf("|    \033[32m%d\033[0m    |\n",j+3));


                    }
                    else if((j+1)<ns){

                        printf("                        ---------------------\n");
         (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    ",j+1):printf("                        |    \033[32m%d\033[0m    ",j+1));(foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m    |\n",j+2):printf("|    \033[32m%d\033[0m    |\n",j+2));

                    }
                    else{
                         printf("                        -----------\n");

      (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m    |\n",j+1):printf("                        |    \033[32m%d\033[0m    |\n",j+1));


                    }}else{

                    if((j+3)<ns){
                            printf("                        ---------------------                         ---------------------\n");

         (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   ",j+1):printf("                        |    \033[32m%d\033[0m   ",j+1));(foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |                         ",j+2):printf("|    \033[32m%d\033[0m   |                         ",j+2));(foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m   ",j+3):printf("|    \033[32m%d\033[0m   ",j+3));(foundseat[j+3]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+4):printf("|    \033[32m%d\033[0m   |\n",j+4));

                    }
                    else if((j+2)<ns){
                        printf("                        ---------------------                          -----------\n");

         (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   ",j+1):printf("                        |    \033[32m%d\033[0m   ",j+1));(foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |                         ",j+2):printf("|    \033[32m%d\033[0m   |                         ",j+2));(foundseat[j+2]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+3):printf("|    \033[32m%d\033[0m   |\n",j+3));


                    }
                    else if((j+1)<ns){

                        printf("                        ---------------------\n");
         (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   ",j+1):printf("                        |    \033[32m%d\033[0m   ",j+1));(foundseat[j+1]=='1'?printf("|    \033[31m%d\033[0m   |\n",j+2):printf("|    \033[32m%d\033[0m   |\n",j+2));

                    }
                    else{
                         printf("                        -----------\n");

      (foundseat[j]=='1'?printf("                        |    \033[31m%d\033[0m   |\n",j+1):printf("                        |    \033[32m%d\033[0m   |\n",j+1));


                    }





                    }





            }






            }
