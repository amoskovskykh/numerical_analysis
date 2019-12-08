#include "header.h"

_Bool mx_allowed(char c)
{
    if (mx_isdigit(c) || mx_isspace(c)
        || c == ',' || c == '.' || c == ';' 
        || c == '-' || c == '+') 
    {
        return true;
    } else 
        return false;
}
