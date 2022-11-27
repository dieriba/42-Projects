#include "libft.h"

int	check_empty(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!argv[i][0])
			return (1);
	}
	return (0);
}