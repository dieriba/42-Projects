#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int ft_strncmp(char *s, char *s2, int len)
{
    size_t  i;
    printf("s1 : %s", s);
    printf("s2 : %s", s2);
    i = -1;
    while ((s[++i] && s2[i]) && (s[i] == s2[i]) && --len)
        ;
    if (!len)
        return (1);
    else
        return (0);
    printf("%d\n", s[i] - s2[i]);
    return (s[i] - s2[i]);
}

size_t  ft_strlens(char *str)
{
    size_t  i;

    i = -1;
    while (str[++i])
        ;
    return (i);
}

int main (int argc, char **argv)
{
    int fd;
    char *str;

    if (argc != 3)
        return (1);
    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY);
    if (fd < 0)
        return (1);
    while (1)
    {
        str = get_next_line(0);
        if (ft_strncmp(str, argv[2], 3))
            break;
        write(fd, str, ft_strlens(str));
    }
    
    close(fd);
}