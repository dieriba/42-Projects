#include "ft_printf.h"

int ft_putnbr_base_hex(unsigned int nbr, int transform, int *count)
{
    const char  *base;

    base = "0123456789abcdef";
    if (nbr > 15)
        ft_putnbr_base_hex((nbr / 16), transform, count);
    if (transform && (((nbr % 16) > 1 && (nbr % 16) < 10) || (nbr % 16) == 0))
        ft_putchar(base[(nbr % 16)]);
    else if (transform)
        ft_putchar(base[(nbr % 16)] - 32);
    else 
        ft_putchar(base[(nbr % 16)]);
    return (*count += 1);
}