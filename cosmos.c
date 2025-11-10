#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i = 1;
    while(i < argc){
        if(strcmp(argv[i], "install") == 0){
            char input[50];
            char cmd1[1024];
            snprintf(cmd1, sizeof(cmd1), "wget https://github.com/Mortem-Metallum/cosmos-repo/%s.tar.gz", input);
            printf("install> ");
            scanf("%s", &input);
            printf("I >>> Executing command: wget %s", input);
            int e = system(cmd1);
            if(e != 0){
                printf("E >>> Failed! %d", e);
                printf("The operation could not complete due to previous errors");
            }    
        }
        } else {
            printf("E >>> Missing operand");
            printf("I >>> Try cosmos --help for more information");
            return 1;
        }
        i++;
    }
    return 0;
}
