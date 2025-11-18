#include "libcosmos.h"


char line[MAX_LINE];
char installto[MAX_LINE] = "/usr/bin";
char depends[MAX_LINE] = "NONE";
char makeflags[MAX_LINE] = "make -j$(nproc)";
char version[MAX_LINE] = "UNKNOWN";
