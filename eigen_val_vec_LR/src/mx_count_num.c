#include "header.h"

int mx_count_num(const char *str)
{
    char del1 = ' ';
    char del2 = '\n';
    int y = 0;
    int len = 0; 
    for (int i = 0; str[i]; i++)
    {
		if (str[i] != del1 && str[i] != del2)
        {
            if ((i > 0) && str[i-1] == del1)
                len++;
            else if ((i > 0) && str[i-1] == del2) {
                len++; 
                y++;
            }
            for (; (str[i+1] != del1 && str[i+1] != del2) && str[i]; i++);
        }
    }
    y++;
    len++;
	if ((y * y) != len)
    {
        mx_printerr("invalid matrix size\n");
        exit(0);
    }
    return y;
}
