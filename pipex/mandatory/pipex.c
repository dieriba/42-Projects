#include "pipex.h"





// int	init(t_info	*info)
// {
	
// }

int		is_valid_path_abs(char *argv)
{
	size_t  i;
    int     find;

    find = 0;
    i = 1;
    while (argv[i])
    {
        while (argv[++i] && argv[i] != '/')
            if (ft_isalnum(argv[i]) && argv[i] != '/' && !find)
                find = 1;
        if (!find)
            return (1);
        find = 0;
    }
    if (argv[--i] == '/')
            return (1);
	return (0);
}

int	is_valid_cmd(char *argv)
{
	size_t	i;

	i = -1;
	while (argv[++i])
	{
		if (!ft_isalnum(argv[i]))
			return (1);
	}
	return (0);
}

int     check_args(char **argv)
{
	int	is_valid;

	is_valid = 0;
    if (argv[1][0] && argv[1][0] == '/')
	{
		is_valid = is_valid_path_abs(argv[1]);
		is_valid = is_valid_path_abs(argv[2]);
	}
	else if (argv[1][0] != '.' && argv[1][0] != '/')
		is_valid = is_valid_cmd;
	else if ()
		
	return (is_valid);
}

int main(int argc, char *argv[], char *envp[])
{
	t_cmd	info;
	ft_memset(&info, 0, sizeof(t_cmd));
    // check(info, argv, envp);

    if (check_args(argv))
		printf("Invalid Path");
	else
		printf("Valid path");
    // while (tab[++i])
    //     execve(tab[i], arg, envp);
}
