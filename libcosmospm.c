#include "libcosmos.h"


char line[MAX_LINE];
char installto[MAX_LINE] = "/usr/bin";
char depends[MAX_LINE] = "NONE";
char makeflags[MAX_LINE] = "make -j$(nproc)";
char version[MAX_LINE] = "UNKNOWN";
char err_symbol[MAX_LINE] = "\e[0;31mE \e[0m>>>";
char warn_symbol[MAX_LINE] = "\e[0;33mW \e[0m>>>";
char info_symbol[MAX_LINE] = "\e[1;37mI \e[0m>>>";
char cosmos_ver[MAX_LINE] = "v1.0.0-beta_release";

void trim(char *str){
    char *end;
    while(*str == ' ' || *str == '\t') str++;
    end = str + strlen(str) - 1;
    while(end > str && (*end == ' ' || *end == '\t')) end--;
    *(end+1) = '\0';
}
