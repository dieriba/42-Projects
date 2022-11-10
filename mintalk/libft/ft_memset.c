#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
    size_t  i;
    unsigned char   *buf;

    i = 0;
    buf = (unsigned char *)s;
    while(i < n)
    {
        buf[i] = c;
        i++;
    }
    return (s);
}