/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:31:37 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 13:34:29 by dtoure           ###   ########.fr       */
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
		free(cmd[i]->cmd);
		if (cmd[i]->args)
			free_tab(cmd[i]->args);
		if (cmd[i]->no_path)
			free_tab(cmd[i]->paths);
		free(cmd[i]);
	}
	free(cmd);
}

void	free_files(t_data *to_free)
{
	size_t	i;

	i = -1;
	if (to_free -> files)
	{
		while (++i < 2)
			free(to_free -> files[i]);
		free(to_free -> files);
	}
}

void	free_all(t_data *to_free, int code)
{
	free_files(to_free);
	free_cmd(to_free -> cmd_data);
	exit(code);
}

void	print_err_and_exit(char *str, t_data *info)
{
	perror(str);
	free_all(info, EXIT_FAILURE);
}
