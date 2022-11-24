/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:16 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 13:49:16 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_tab(char **tab)
{
	size_t	i;
	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		ft_printf("args [%i] %s\n", i + 1, tab[i]);
}

void	print_cmd(t_cmd **cmds)
{
	size_t	i;

	i = -1;
	while (cmds[++i])
	{
		ft_printf("%s \n", cmds[i]-> cmd);
		print_tab(cmds[i]->args);
		print_tab(cmds[i]->paths);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	info;

	if (argc < 5 || check_empty(argc, argv))
	{
		ft_printf("Usage : %s 'file1' 'cmd1' 'cmd2' 'file2'\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ft_memset(&info, 0, sizeof(t_data));
	init_cmd(&info, argv, argc, envp);
	create_pipe(&info);
	// free_all(&info, EXIT_SUCCESS);
}
