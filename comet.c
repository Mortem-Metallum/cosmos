#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf("Usage: comet -d <builddir>\n");
        return 1;
    }

    char builddir[100];
    strncpy(builddir, argv[2], sizeof(builddir)-1);
    builddir[sizeof(builddir)-1] = '\0';

    char ini_path[150];
    snprintf(ini_path, sizeof(ini_path), "%s/buildconf.ini", builddir);

    FILE *ini = fopen(ini_path, "r");
    if(!ini){
        printf("COMET: No buildconf.ini, using default make command\n");
    }

    char line[MAX_LINE];
    char depends[MAX_LINE] = "NONE";
    char makeflags[MAX_LINE] = "make -j$(nproc)";
    char version[MAX_LINE] = "UNKNOWN";

    if(ini){
        while(fgets(line, sizeof(line), ini)){
            line[strcspn(line, "\r\n")] = 0;

            if(line[0] == '#' || line[0] == ';' || line[0] == '\0') continue;

            if(strncmp(line, "depends", 7) == 0){
                sscanf(line, "depends = %255[^\n]", depends);
            } else if(strncmp(line, "makeflags", 9) == 0){
                sscanf(line, "makeflags = %255[^\n]", makeflags);
            } else if(strncmp(line, "version", 7) == 0){
                sscanf(line, "version = %255[^\n]", version);
            }
        }
        fclose(ini);
        char depinstall1[500];
        snprintf(depinstall1, sizeof(depinstall1), "tar zxvf https://raw.githubusercontent.com/Mortem-Metallum/cosmos-repo/%s", depends);
        
    }
    
    printf("COMET: BuildDir=%s\n", builddir);
    printf("COMET: Depends=%s\n", depends);
    printf("COMET: Version=%s\n", version);
    printf("COMET: MakeFlags=%s\n", makeflags);

    char compilecmd[512];
    snprintf(compilecmd, sizeof(compilecmd), "%s -C %s", makeflags, builddir);
    printf("COMET: Running compile command\n:: %s\n", compilecmd);

    int r = system(compilecmd);
    if(r != 0){
        printf("COMET: Failed!\n");
        return 1;
    }
    printf("COMET: Finished compiling: %s\n", builddir);

    return 0;
}

