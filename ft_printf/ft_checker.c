#include "ft_printf.h"

int ft_valid(char c)
{
    const char *base;
    size_t i;

    i = -1;
    base = BASE_FORMAT;
    while (base[++i])
        if (base[i] == c)
            return (1);
    return (0);
}

int valid_format(const char *format)
{
    size_t i;
    char *str;

    str = (char *)format;
    i = -1;
    while (str[++i])
    {
        if ((str[i] == '%' && ft_valid(str[++i])))
            return (1);
        i++;
    }
    return (0);
}