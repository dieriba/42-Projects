/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:11:12 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/19 16:13:37 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"
typedef struct t_cmd t_cmd;
typedef struct t_data
{
	char	**files;
	t_cmd	**cmd_data;
	int		pipe[2];
}	t_data;

typedef struct t_cmd
{
	char	*cmd;
	char	**args;
	char	**paths;
	char	*path;
} t_cmd;
#endif