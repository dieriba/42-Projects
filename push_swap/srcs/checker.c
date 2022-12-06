#include "push.h"

int		check_args(int argc, char **argv)
{
    int	i;
    int	j;

    j = -1;
    i = 0;
    while (++i < argc)
    {
		if (!argv[i][0] || (argv[i][0] == '0' && ft_strlen(argv[i]) > 1))
			return (0);
        if (argv[i][0] == '-' && !argv[i][1])
            return (0);
        if (argv[i][0] == '-')
			j++;
        while (argv[i][++j])
        {   
            if (!ft_isdigit(argv[i][j]))
            {
                ft_putstr_fd("Only digits are accepted as arguments !\n", 2);
                return (0);
            }
        }
        j = -1;
    }
    return (1);
}

int		check_double(int argc, char **argv)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (++i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
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
	if (argc < 2)
    {
        ft_putendl_fd("Usage: ./push_swap args1 arg2s....argsn", 2);
        return (0);
    }
	if (!check_args(argc, argv))
	{
		ft_putendl_fd("Args entered are not valid", 2);
		return (0);
	}
	if (!check_double(argc, argv))
	{
		ft_putendl_fd("A number cannont be entered more than once", 2);
		return (0);
	}
	if (!check_number(argc, argv))
	{
		ft_putendl_fd("One of the numbers is above the max int or below the min int limit...", 2);
		return (0);
	}
	return (1);
}