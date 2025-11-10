// The Cosmos Package Manager
// Copyright 2025, John Doe. This software is under the BSD 3-clause license. Read LICENSE for more information

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i = 1;
    while(i < argc){
        if(strcmp(argv[i], "install") == 0){
            char input[50];
            char cmd1[1024];
            char cmd2[1024];
            char cmd3[1024];

            strncpy(input, argv[2], sizeof(input) - 1);
            input[sizeof(input) - 1] = '\0';

            snprintf(cmd1, sizeof(cmd1), "wget https://raw.githubusercontent.com/Mortem-Metallum/cosmos-repo/main/%s.tar.gz", input);
            snprintf(cmd2, sizeof(cmd2), "tar xvf %s.tar.gz", input);
            snprintf(cmd3, sizeof(cmd3), "cd %s", input);
            printf(":: %s\n", cmd1);

            int e = system(cmd1);
            if(e != 0){
                printf("E >>> Failed!\n");
                printf("The operation could not complete due to previous errors\n");
            }

            printf(":: %s\n", cmd2);
            int e2 = system(cmd2);
            if(e2 != 0){
                printf("E >>> Failed!\n");
                printf("The operation could not complete due to previous errors\n");
            }
            
            int e3 = system(cmd3);
            printf(":: %s\n", cmd3);
            if(e3 != 0){
                printf("E >>> Failed!\n");
                printf("The operation could not complete due to previous errors\n");
            }
        } else if(strcmp(argv[i], "--help") == 0){
            printf("Usage: cosmos [ OPERAND ] [ PACKAGE ]\n");
            printf("Operands: \n");
            printf("install: Installs specified package\n");
            return 0;
        } else {
            return 1;
        }

        i++;
    }
    return 0;
}
