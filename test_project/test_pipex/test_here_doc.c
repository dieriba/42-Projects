#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int ft_strcmp(const char *s1, const char *s2, size_t n)
{
   	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && (i < n) && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
	int 	fd;
	char	*lines;
	int		limiter;


	int len = ft_strlens(argv[2]);
	fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		str = get_next_line(0,limiter);
		limiter = ft_strcmp(str, argv[2], len);
		if (!limiter)
			break ;
		write(fd, str, ft_strlens(str));
		free(str);
	}
	get_next_line(0, limiter);
	free(str);
	close(fd);
}