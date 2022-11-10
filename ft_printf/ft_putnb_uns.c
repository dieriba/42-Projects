#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int nbr, int *count)
{
	if (nbr > 9)
		ft_putnbr_uns((nbr / 10), count);
	ft_putchar((nbr % 10) + '0');
	return (*count += 1);
}