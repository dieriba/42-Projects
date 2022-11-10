#include "libft.h"

int check_overlap(const void *dest, const void *src, size_t len)
{
    unsigned char *s;
    unsigned char *s_last;
    unsigned char *d;
    
    s = (unsigned char *) src;
    s_last = (unsigned char *) (src + len - 1);
    d = (unsigned char *) dest;
    size_t  i;

    i = 0;
    while (i < len)
    {
        if ((s == &d[i]) || (s_last == &d[i]))
            return (1);
        i++;
    }
    return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
    void    *buff;

    if(!src && !dest)
        return (NULL);
    if(n == 0)
        return (dest);
    if(!check_overlap(dest, src, n))
    {
        ft_memcpy(dest, src, n);
        return (dest);
    }
    buff = malloc(sizeof(char) * n);
    if (!buff)
        return (NULL);
    ft_memcpy(buff, src, n);
    ft_memcpy(dest, buff, n);
    free(buff);
    buff = NULL;
    return (dest);
}