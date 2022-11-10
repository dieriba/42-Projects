#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args_infos;
    size_t i;
    char *str;
    int count;

    va_start(args_infos, format);
    i = 0;
    count = 0;
    str = (char *)format;
    while (str[i])
    {
        if (str[i] == '%')
            count += ft_display_format(str[++i], args_infos);
        else
            count += ft_putchar(str[i]);
        i++;
    }
    va_end(args_infos);
    return (count);
}
