#include "libft.h"

int	ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while(ft_isspace(nptr[i]))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (ft_isdigit(nptr[i]))
    {
        res = res * 10 + (nptr[i] - '0');
        i++;
    }
    return (res * sign);
}