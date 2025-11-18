// The Cosmos Package Manager
// Copyright 2025, John Doe. This software is under the BSD 3-clause license. Read LICENSE for more information

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cosmos.h"

int main(int argc, char *argv[]){
    int i = 1;
    if(argc < 2){
        printf("E >>> Missing operand\nI >>> Try cosmos --help for more information\n");
    }
    while(i < argc){
        if(strcmp(argv[i], "install") == 0){
            char input[250];
            char confirm[10];
            char cmd1[1024];
            char cmd2[350];
            char cmd3[350];
            char cmd4[350];
            char mrproper[350];

            strncpy(input, argv[2], sizeof(input) - 1);
            input[sizeof(input) - 1] = '\0';

            snprintf(cmd1, sizeof(cmd1), "wget https://raw.githubusercontent.com/Mortem-Metallum/cosmos-repo/main/%s.tar.gz", input);
            snprintf(cmd2, sizeof(cmd2), "tar xvf %s.tar.gz", input);
            snprintf(cmd3, sizeof(cmd3), "comet -d %s", input);
            snprintf(cmd4, sizeof(cmd4), "cp ./%s/%s %s", input, input, installto);
            snprintf(mrproper, sizeof(mrproper), "rm -rf %s %s.tar.gz", input, input);

            printf("I >>>     Information, W >>>     Warning, ::     Command, E >>>     Error\n");
            printf(":: %s\n", cmd1);

            int e = system(cmd1);
            if(e != 0){
                printf("E >>> Failed!\n");
                printf("The operation could not complete due to previous errors\n");
                return 1;
            } else {
                printf("The following packages will be INSTALLED:\n");
                printf("%s\n\n", input);
                printf("Is this OK? [ Y/N ]: ");
                fgets(confirm, sizeof(confirm), stdin);
                confirm[strcspn(confirm, "\n")] = '\0';
                if(strcmp(confirm, "N") == 0 || strcmp(confirm, "n") == 0){
                    printf("I >>> Goodbye!\n");
                    return 0;
                } else if(strcmp(confirm, "Y") == 0 || strcmp(confirm, "y") == 0){
                    ;
                } else {
                    printf("E >>> Invalid response.\n");
                    return 1;
                }
            }

            printf(":: %s\n", cmd2);
            int e2 = system(cmd2);
            if(e2 != 0){
                printf("E >>> Failed!\n");
                printf("The operation could not complete due to previous errors\n");
                return 1;
            }

            printf(":: %s\n", cmd3);
            int e3 = system(cmd3);
            if(e3 != 0){
                printf("E >>> Failed!\n");
                printf("The operation could not complete due to previous errors\n");
                return 1;
            }

            printf(":: %s\n", cmd4);
            int e4 = system(cmd4);
            if(e4 != 0){
                printf("E >>> Failed!\n");
                printf("The operation could not complete due to previous errors\n");
                return 1;
            }
            printf("I >>> Cleaning up...\n");
            printf(":: %s\n", mrproper);
            int e5 = system(mrproper);
            if(e5 != 0){
                printf("E >>> Failed!");
                return 1;
            }
            printf("I >>> Done!\n");
        } else if(strcmp(argv[i], "--help") == 0){
            printf("Usage: cosmos [ OPERAND ] [ PACKAGE ]\n");
            printf("Operands: \n\n");
            printf("install: Install the specified package\n");
            printf("--help: Display this help and exit\n");
            return 0;
        } else {
            return 1;
        }

        i++;
    }
    return 0;
}
