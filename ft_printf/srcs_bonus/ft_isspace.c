#include "ft_printf_bonus.h"

int	ft_isspace(const char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}