#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = -1;
	while ((s1[++i] && s2[i]) && s1[i] == s2[i])
		;
	return (s1[i] - s2[i]);	
}