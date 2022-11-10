#include "ft_print_bonus.h"


int ft_atoi(const char *format, int *pos)
{
    char    *str;
    int     num;
    int     i;

    i = *pos;
    num = 0;
    str = (char *)format;
    while (str[++i] && ft_isdigit(str[i]))
        num = num + str[i] - '0';
    return (num);
}