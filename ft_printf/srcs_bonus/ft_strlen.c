#include "ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}
