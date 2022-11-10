#include "ft_printf.h"

int ft_write_hex_adress(unsigned long int nbr, char *base, int first, int *count)
{
    if (first)
    {
        write(1, "0x", 2);
        *count = 2;
    }
    if (nbr > 15)
        ft_write_hex_adress((nbr / 16), base, 0, count);
    ft_putchar(base[(nbr % 16)]);
    return (*count += 1);
}