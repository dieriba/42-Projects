#include "ft_printf_bonus.h"

int ft_getlen(int n)
{
	int len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len *= 10;
	}
	return (len);
}

int	ft_putnbr(int n, int *count)
{
	long int	nbr;
	int			len;
	int			val;

	nbr = -(n < 0) * n + (n > 0) * n;
	val = (n < 0);
	len = ft_getlen(n);
	if (n < 0 && !(*count))
		ft_putchar('-');
	while (len != 0)
	{
		ft_putchar((nbr / len) + '0');
		nbr %= len;
		len /= 10;
		val++;
	}
	if (!*(count))
		*count = val;
	return (*count);
}