#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  int i = 1;
  while(i < argc){
    if(strcmp(argv[i], "-d") == 0){
      char builddir[100];
      char compilecmd[350];

      
      strncpy(builddir, argv[2], sizeof(builddir) - 1);
      builddir[sizeof(builddir) - 1] = '\0';

      snprintf(compilecmd, sizeof(compilecmd), "make -C %s -j$(nproc)", builddir);
      printf("COMET: Running compile command\n");
      printf(":: %s\n", compilecmd);
      int r1 = system(compilecmd);
      if(r1 != 0){
        printf("COMET: Failed!");
        return 1;
      }
      printf("COMET: Finished compiling: %s\n", builddir);
      return 0;
    }
  }
  i++;
  return 0;
}
