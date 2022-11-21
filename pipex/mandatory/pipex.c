#include "pipex.h"

// int	is_valid_cmd(char *argv)
// {

// }

void	print_tab(char **tab)
{
	size_t	i;
	
	if (!tab)
	{
		ft_printf("No tab\n");
		return ;
	}
	i = -1;
	while(tab[++i])
		ft_printf("%s ", tab[i]);
}


int main(int argc, char *argv[], char *envp[])
{
	t_data	info;

	if (argc != 5 || check_empty(argc, argv))
	{
		ft_printf("Usage : %s 'file1' 'cmd1' 'cmd2' 'file2'\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ft_memset(&info, 0, sizeof(t_data));
	info.files = NULL;
    info.cmd_data = NULL;
	init_cmd(&info, argv, envp);
	// print_struct(&info);
	// print_err_and_exit("END", &info);
}
