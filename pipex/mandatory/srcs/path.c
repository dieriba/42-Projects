/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:41:48 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 13:44:47 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_path(t_cmd *cmds)
{
	size_t	i;
	char	*tmp;

	i = -1;
	cmds -> paths = ft_split(cmds -> path + 5, ':');
	if (!cmds -> paths)
		print_err_and_exit("Failled to allocate memory", cmds -> info);
	while (cmds -> paths[++i])
	{
		tmp = cmds -> paths[i];
		cmds -> paths[i] = ft_strjoin(cmds -> paths[i], cmds -> cmd);
		if (!cmds -> paths[i])
			print_err_and_exit("Failled to allocate memory", cmds -> info);
		free(tmp);
	}
}

void	set_path(t_cmd **cmds)
{
	size_t	i;

	i = -1;
	while (cmds[++i])
	{
		if (cmds[i]-> no_path)
			create_path(cmds[i]);
		else
			cmds[i]-> paths = 0;
	}
}

void	set_path_type(t_cmd **cmds)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (cmds[++i])
	{
		if (cmds[i]-> cmd[j] != '/' && cmds[i]-> cmd[j] != '.')
		{
			cmds[i]-> no_path = 1;
			cmds[i]-> cmd = ft_strjoin("/", cmds[i]-> cmd);
			if (!cmds[i]-> cmd)
				print_err_and_exit("Failled to allocate memory",
					cmds[0]-> info);
		}
		else
			cmds[i]-> no_path = 0;
	}		
}
