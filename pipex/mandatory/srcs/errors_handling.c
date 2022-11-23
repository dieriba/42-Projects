/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:31:37 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 21:46:23 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_cmd **cmd)
{
	size_t	i;

	if (!cmd)
		return ;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i]-> cmd)
			free(cmd[i]-> cmd);
		if (cmd[i]-> args)
			ft_free_tab(cmd[i]-> args);
		if (cmd[i]-> paths)
			ft_free_tab(cmd[i]-> paths);
		free(cmd[i]);
	}
	free(cmd);
}

void	free_files(char **files)
{
	size_t	i;

	i = -1;
	if (!files)
		return ;
	while (++i < 2)
		free(files[i]);
	free(files);
}

void	free_all(t_data *to_free, int code)
{
	free_files(to_free -> files);
	free_cmd(to_free -> cmd_data);
	exit(code);
}

void	print_err_and_exit(char *str, t_data *info, int type)
{
	if (!type)
		ft_putstr_fd(str, 2);
	else
		perror("Error");
	if (info -> init_pipes)
	{
		if (close(info -> pipes[0]) < 0 || close(info -> pipes[1]) < 0)
		{
			print_err_and_exit("Error", info, 1);
			info -> init_pipes = 0;
		}
	}
	free_all(info, EXIT_FAILURE);
}
