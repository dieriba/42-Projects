#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
    size_t  i;
    long int  j;

    i = 0;
    j = -1;
    if (c == 0)
        return ((char *)(s) + ft_strlen(s));
    while (s[i])
    {
        if(s[i] == (char) c)
            j = i;
        i++;
    }
    if (j > -1)
        return ((char *) (s + j));
    return (NULL);
}