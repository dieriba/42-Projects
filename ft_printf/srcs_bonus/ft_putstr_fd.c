#include "ft_printf_bonus.h"

int	ft_putstr_fd(char *s, int fd)
{
    int len;
    if (s != NULL)
    {
        len = ft_strlen(s);
        write (fd, s, len);
    }
    else 
    {
        write (fd, "(null)", 6);
        len = 6;
    }
    return (len);
}