#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
        if (dest == NULL && src == NULL)
            return (NULL);
        char    *dest_ptr;
        char    *src_ptr;
        size_t  i;

        i = 0;
        dest_ptr = (char *)dest;
        src_ptr = (char *)src;
        while (i < n)
        {
            dest_ptr[i] = src_ptr[i];
            i++;
        }
        return (dest);
}