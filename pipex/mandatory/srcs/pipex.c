#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data	info;

	if (argc != 5 || check_empty(argc, argv))
	{
		ft_printf("Usage : %s 'file1' 'cmd1' 'cmd2' 'file2'\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ft_memset(&info, 0, sizeof(t_data));
	init_cmd(&info, argv, envp);
	create_pipe(&info);
	free_all(&info, EXIT_SUCCESS);
}
