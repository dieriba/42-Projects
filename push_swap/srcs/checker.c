#include "push.h"

int		check_args(int argc, char **argv)
{
    int	i;
    int	j;

    j = -1;
    i = 0;
    while (++i < argc)
    {
		if (!ft_strlen(argv[i]))
			return (0);
        if (argv[i][0] == '-' && !argv[i][1])
            return (0);
        if (argv[i][0] == '-')
			j++;
        while (argv[i][++j])
        {   
            if (!ft_isdigit(argv[i][j]))
                return (0);
        }
        j = -1;
    }
    return (1);
}

int		check_double(int argc, char **argv)
{
	int	i;
	int	j;
	int	first;
	int	second;


	j = 0;
	i = 0;
	while (++i < argc - 1)
	{
		first = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			second = ft_atoi(argv[j]);
			if (first == second)
				return (0);
			j++;
		}
	}
	return (1);
}

int		check_max_min(char *number, int len)
{
	size_t	i;
	char	*str;

	if (len == 11)
		str = MIN_INT_S;
	else
		str = MAX_INT_S;
	i = -1;
	while (number[++i])
	{
		if (number[i] > str[i])
			return (0);
	}
	return (1);
}

int		check_number(int argc, char **argv)
{
	int	i;
	int	len;

	i = 0;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		if (argv[i][0] == '-' && len > 11)
			return (0);
		else if (argv[i][0] != '-' && len  > 10)
			return (0);
		if (len == 10 || len == 11)
			if (!check_max_min(argv[i], len))
				return (0);
	}
	return (1);
}

int	check(int argc, char **argv)
{
	char	**tab;

	tab = get_args(argc, argv);
	if (!tab)
		return (0);
	if (argc < 2)
        return (0);
	if (!check_args(argc, argv))
		return (ft_error("Error\n", 0, NULL));
	if (!check_number(argc, argv))
		return (ft_error("Error\n", 0, NULL));
	if (!check_double(argc, argv))
		return (ft_error("Error\n", 0, NULL));
	return (1);
}