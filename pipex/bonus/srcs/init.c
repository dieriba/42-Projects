/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:34:34 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/25 23:08:45 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_files(t_data *info, char *files_one, char *files_two)
{
	char	**files;
	size_t	i;
	char	*file;

	i = -1;
	files = ft_calloc(sizeof(char *), 2);
	if (!files)
		print_err_and_exit("Failled to allocate memory", info, 0);
	while (++i < 2)
	{
		if (i == 0)
			file = files_one;
		else
			file = files_two;
		if (info -> here_doc)
			file = create_file(info);
		files[i] = ft_strdup(file);
		if (!files[i])
			print_err_and_exit("Failled to allocate memory", info, 0);
	}
	info -> files = files;
}

void	fill_struct(t_cmd **cmds, char **argv)
{
	char	**tab;
	size_t	i;

	i = -1 + 2 + (cmds[0] -> info -> here_doc == 1);
	while (cmds[++i])
	{
		tab = ft_split(argv[i], ' ');
		if (!tab)
			print_err_and_exit("Failled to allocate memory", cmds[0]-> info, 0);
		cmds[i]-> cmd = tab[0];
		cmds[i]-> args = tab;
	}
}

void	set_cmds_data(t_data *info, t_cmd **cmds, char *path)
{
	int	i;

	i = -1;
	while (++i < info -> num_cmds)
	{
		cmds[i]-> info = info;
		cmds[i]-> path = path;
	}
}

void	set_cmd(t_cmd *cmd, char *envp[])
{
	cmd -> args = NULL;
	cmd -> no_path = 0;
	cmd -> cmd = NULL;
	cmd -> paths = NULL;
	cmd -> envp = envp;
}

void	init_cmd(t_data *info, char **argv, int argc, char **envp)
{
	t_cmd	**cmds;
	int		i;

	info -> files = NULL;
	info -> num_cmds = argc - 3 - (info -> here_doc == 1);
	info -> prev_pipes = -1;
	info -> LIMITER = argv[2];
	i = -1;
	cmds = ft_calloc(sizeof(t_cmd *), info -> num_cmds + 1);
	if (!cmds)
		print_err_and_exit("Failled to allocate memory", info, 0);
	info -> cmd_data = cmds;
	while (++i < info -> num_cmds)
	{
		cmds[i] = malloc(sizeof(t_cmd));
		if (!cmds[i])
			print_err_and_exit("Failled to allocate memory", info, 0);
		set_cmd(cmds[i], envp);
	}
	init_files(info, argv[1], argv[argc - 1]);
	set_cmds_data(info, info -> cmd_data, find_path(envp));
	fill_struct(cmds, argv);
	set_path_type(cmds);
	set_path(cmds);
}
