#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
        size_t  i;
        size_t  j;
        char    *buff;

        if (!s1 || !s2)
            return (NULL);
        i = ft_strlen(s1);
        j = ft_strlen(s2);
        buff = malloc(sizeof(char) * (i + j + 1));
        if (!buff)
            return (NULL);
        ft_memcpy(buff, s1, i);
        ft_memcpy(buff + i, s2, (j + 1));
    return (buff);
}