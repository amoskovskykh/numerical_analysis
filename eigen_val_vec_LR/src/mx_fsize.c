#include "header.h"

int mx_fsize(const char *f)
{
    int file = open(f, O_RDONLY);
    if(file == -1) 
    {
        mx_printerr("file does not exist\n");
        exit(0);
    }
    int i;
    char c;
    for(i = 0; read(file, &c, 1) > 0; i++);
    close(file);
    return i;
}
