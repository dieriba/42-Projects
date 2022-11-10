#include "minitalk.h"

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        res = res * 10 + (nptr[i] - '0');
        i++;
    }
    return (res * sign);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr > 9)
		ft_putnbr_fd((nbr / 10), fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}