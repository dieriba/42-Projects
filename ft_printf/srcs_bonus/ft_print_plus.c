#include "ft_printf_bonus.h"

static int ft_getlen(int n)
{
    int len;

    if (n == 0)
        return (1);
    len = (n < 0);
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

int ft_print_plus(const char *format, va_list args_infos, size_t *i)
{
    int     format_num;
    int     len;
    char    *str;
    va_list args_infos_cpy;
    size_t     tmp;

    va_copy(args_infos_cpy, args_infos);
    format_num = (int)va_arg(args_infos_cpy, int);
    va_end(args_infos_cpy);
    len = ft_getlen(format_num);
    tmp = *i;
    str = (char *)format;
    while (str[tmp] == '+')
        tmp++;
    if (str[tmp] == 'd' || str[tmp] == 'i')
        *i = tmp;
    if (format_num < 0)
        ft_putchar('-');
    else
        ft_putchar('+');
    if (format_num == 0)
        ft_putchar('0');
    return (len + (format_num >= 0));
}