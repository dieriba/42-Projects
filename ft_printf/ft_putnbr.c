#include "ft_printf.h"

int	ft_putnbr(int n, int *count)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		*count = 1;
		ft_putchar('-');
	}
	if (nbr > 9)
		ft_putnbr((nbr / 10), count);
	ft_putchar((nbr % 10) + '0');
	return (*count += 1);
}