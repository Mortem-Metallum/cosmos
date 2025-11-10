#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i = 1;
    while(i < argc){
        if(strcmp(argv[i], "install") == 0){
            char input[50] = "";
            printf("install> ");
            scanf("%s", &input);
            try{
                printf("I >>> Executing command: wget %s", input);
                system("wget %s", input);
            } catch (e) {
                printf("E >>> Failed! %d", e);
                printf("The operation could not complete due to previous errors");
                return 1;
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
