/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:37:31 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/26 19:54:30 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*create_file(t_data *info)
{
	char	*file;
	int		fd;
	char	*limiter;

	limiter = info -> limiter;
	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0)
		print_err_and_exit("Error", NULL, info, 1);
	// ft_strcmp(get_next_line(fd), limiter);
	file = NULL;
	return (file);
}

void	wait_all_child(t_cmd **cmds)
{
	size_t	i;
	int		status;
	t_data	*info;

	info = cmds[0]-> info;
	i = -1;
	while (cmds[++i])
	{
		if (waitpid(cmds[i]-> pid, &status, 0) < 0)
			print_err_and_exit("Error with waitpid", NULL, info, 1);
	}
	info -> status = -1;
	if (WIFEXITED(status))
		info -> status = WEXITSTATUS(status);
}
