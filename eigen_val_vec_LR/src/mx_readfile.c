#include "header.h"

void mx_readfile(char *f, char *s)
{
    int file = open(f, O_RDONLY);
    int i = 0 ;
    while (read(file, &s[i], 1) > 0)
    {
        if (s[i] == ',' || s[i] == ';')
            *s = ' ';
        else if (!mx_allowed(s[i])) {
            mx_printerr("invalid input data\n");
            exit(0);
        }
        s++;
    }
    close(file);
}
