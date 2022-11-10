#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
        void    *buff;

        buff = malloc(size * nmemb);
        if (!buff)
            return (NULL);
        ft_bzero(buff, (size * nmemb));
        return (buff);
}