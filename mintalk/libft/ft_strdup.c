#include "libft.h"

char	*ft_strdup(const char *s)
{
    char    *buff;
    size_t  i;

    i = 0;
    buff = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
    if(!buff)
        return (NULL);
    while (s[i])
    {
        buff[i] = s[i];
        i++;
    }
    buff[i] = 0;
    return (buff);
}