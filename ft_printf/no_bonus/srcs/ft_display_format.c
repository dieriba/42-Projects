#include "ft_printf.h"

int ft_display_format(char c, va_list args_infos)
{
    int count;

    count = 0;
    if (c == 'c')
        count = ft_putchar((int)va_arg(args_infos, int));
    else if (c == 's')
        count = ft_putstr_fd((char *)va_arg(args_infos, char *), 1);
    else if (c == 'p')
        count = ft_write_hex_adress((unsigned long int)va_arg(args_infos, unsigned long int), "0123456789abcdef", 1, &count);
    else if (c == 'd' || c == 'i')
        count = ft_putnbr((int)va_arg(args_infos, int), &count);
    else if (c == 'u')
        count = ft_putnbr_uns((unsigned int)va_arg(args_infos, unsigned int), &count);
    else if (c == 'x')
        count = ft_putnbr_base_hex((unsigned int)va_arg(args_infos, unsigned int), 0, &count);
    else if (c == 'X')
        count = ft_putnbr_base_hex((unsigned int)va_arg(args_infos, unsigned int), 1, &count);
    else if (c == '%')
        count = ft_putchar('%');
    if (!count && !ft_valid(c))
        count = ft_print_no_format(c);
    return (count);
}