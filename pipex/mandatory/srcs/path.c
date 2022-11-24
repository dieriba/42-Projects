/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:41:48 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/24 17:09:09 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_path(t_cmd *cmds)
{
	char	**tab;

	cmds -> paths = ft_split(cmds -> path + 5, ':');
	if (!cmds -> paths)
		print_err_and_exit("Failled to allocate memory", cmds -> info, 0);
	tab = ft_dup_tab(cmds -> paths, cmds -> cmd);
	if (!tab)
		print_err_and_exit("Failled to allocate memory", cmds -> info, 0);
	cmds -> paths = tab;
}

void	set_path(t_cmd **cmds)
{
	size_t	i;

	i = -1;
	while (cmds[++i])
	{
		if (cmds[i]-> no_path)
			create_path(cmds[i]);
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
		if (cmds[i]-> cmd[j] != '/' && cmds[i]-> cmd[j] \
		!= '.' && !ft_strchr(cmds[i]-> cmd, '/'))
		{
			cmds[i]-> no_path = 1;
			cmds[i]-> cmd = ft_strjoin("/", cmds[i]-> cmd);
			if (!cmds[i]-> cmd)
				print_err_and_exit("Failled to allocate memory",
					cmds[0]-> info, 0);
		}
	}		
}
