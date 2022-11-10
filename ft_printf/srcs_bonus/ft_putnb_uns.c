#include "ft_printf_bonus.h"

static unsigned int	get_len(unsigned int n, int *count)
{
	unsigned int	len;

	if (*(count) && !n)
		return (0);
	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len *= 10;
	}
	return (len);
}

int ft_putnbr_uns(unsigned int n, int *count)
{
	unsigned int len;
	int val;

	val = 0;
	len = get_len(n, count);
	while (len != 0)
	{
		ft_putchar((int)(n / len) + '0');
		n %= len;
		len /= 10;
		val++;
	}
	if (!*(count))
		*count = val;
	return (*count);
}