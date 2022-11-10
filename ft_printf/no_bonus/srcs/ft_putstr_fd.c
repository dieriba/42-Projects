#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
    int len;
    if (!s)
    {
        write(fd, "(null)", 6);
        return (6);
    }
    len = ft_strlen(s);
    write (fd, s, len);
    return (len);
}