#include "ft_printf_bonus.h"

int ft_print_no_format(int c)
{
    ft_putchar('%');
    ft_putchar(c);
    return (2);
}