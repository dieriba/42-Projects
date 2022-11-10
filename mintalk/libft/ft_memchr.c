#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    unsigned char *buf;

    i = 0;
    buf = (unsigned char*) s;
    while (i < n)
    {
        if (buf[i] == (unsigned char)c)
            return ((void *)(s + i));
        i++;
    }
    return (NULL);
}