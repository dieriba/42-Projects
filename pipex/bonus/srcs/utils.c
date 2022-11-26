/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:37:31 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/26 16:46:27 by dtoure           ###   ########.fr       */
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
		print_err_and_exit("Error", info, 1);
	ft_strcmp(get_next_line(fd), limiter);
	file = NULL;
	return (file);
}
