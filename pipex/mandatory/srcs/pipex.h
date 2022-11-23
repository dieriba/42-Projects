/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:11:12 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 13:51:34 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct t_cmd	t_cmd;
typedef struct t_data	t_data;
typedef struct t_data
{
	char	**files;
	t_cmd	**cmd_data;
}	t_data;

typedef struct t_cmd
{
	char	*cmd;
	char	*envp;
	char	*base_cmd;
	char	**args;
	char	**paths;
	char	*path;
	t_data	*info;
	int		no_path;
}	t_cmd;

void	free_all(t_data *to_free, int code);
void	create_pipe(t_data *data);
void	print_err_and_exit(char *str, t_data *info);
void	init_cmd(t_data *info, char **argv, char **envp);
void	set_path_type(t_cmd **cmds);
void	set_path(t_cmd **cmds);
char	*find_path(char **envp);
int		check_empty(int argc, char **argv);
#endif