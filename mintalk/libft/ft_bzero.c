#include "libft.h"


void	ft_bzero(void *s, size_t n)
{
    size_t  i;
    char*  buf;

    i = -1;
    buf = (char *) s;
    while (++i < n)
        buf[i] = 0;
}