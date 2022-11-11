#include "ft_printf.h"

int	ft_print_char(int len, int c)
{
	int  i;

	i = -1;
	while (++i < len)
		ft_putchar(c);
	return (i);
}