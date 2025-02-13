#include<stdio.h>
#include<math.h>
#include <string.h>
int main(){
 char x[15] = "dhakabangkok";
    FILE *bus = fopen("test.txt", "r");
    char line[100];


    while (fgets(line, sizeof(line), bus)){
        // Check if the line starts with x
        printf("%s\n",line);
        if (strncmp(line, x, strlen(x)) == 0) {
            // Extract values using '$' as a delimiter
            char *route = strtok(line, "$");
            char *bus_name = strtok(NULL, "$");
            char *price = strtok(NULL, "$");

                printf("Route: %s\n", route);
                printf("Bus Name: %s\n", bus_name);
                printf("Price: %s\n", price);

        }
    }

    fclose(bus);



    char destination[100][100]={"Chittagong","Cox's Bazar","Khulna","Faridpur","Barishal"};
    for(int i=0;i<5;i++){

        printf("%s\n",destination[i]);

    }


return 0;}
