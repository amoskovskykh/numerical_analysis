#include "header.h"

double mx_atof(char ** s)
{
    if(*s == NULL)
        return 0;

    int sign = 1;
    double mult = 1;
    double sum = 0;

    while(mx_isspace(**s))
        (*s)++;
    if(**s == '-') {
        sign = -1;
        (*s)++;
    }
    if(**s == '+')
        (*s)++;
    while(mx_isdigit(**s))
    {
        sum = sum * 10 + sign * (**s - '0');
        (*s)++;
    }
    if(**s != '.')
        return sum;
    (*s)++;
    while(mx_isdigit(**s))
    {
        mult /= 10;
        sum = sum + mult * sign * (**s - '0'); 
        (*s)++;
    }
    return sum;
}

