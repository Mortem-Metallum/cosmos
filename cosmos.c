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

            printf("install> ");
            scanf("%49s", input);

            snprintf(cmd1, sizeof(cmd1), "wget https://raw.githubusercontent.com/Mortem-Metallum/cosmos-repo/main/%s.tar.gz", input);
            printf("I >>> Executing command: wget %s\n", input);

            int e = system(cmd1);
            if(e != 0){
                printf("E >>> Failed! %d\n", e);
                printf("The operation could not complete due to previous errors\n");
            } 
        } else {
            printf("E >>> Missing operand\n");
            printf("I >>> Try cosmos --help for more information\n");
            return 1;
        }

        i++;
    }
    return 0;
}
