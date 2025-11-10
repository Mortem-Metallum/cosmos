#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i = 1;
    while(i < argc){
        if(strcmp(argv[i], "in") == 0){
        
        } else {
            printf("cosmos: missing operand");
            printf("cosmos: try cosmos --help for more information");
        }
        i++;
    }
    return 0;
}