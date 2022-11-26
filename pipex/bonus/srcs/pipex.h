/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:11:12 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/26 16:32:14 by dtoure           ###   ########.fr       */
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
# include "../libft/get_next_line/get_next_line.h"

typedef struct t_cmd	t_cmd;
typedef struct t_data	t_data;

typedef struct t_data
{
	int		here_doc;
	int		num_cmds;
	t_cmd	**cmd_data;
	char	**files;
	int		init_pipes;
	int		pipes[2];
	int		prev_pipes;
	char	*limiter;
}	t_data;

typedef struct t_cmd
{
	t_data	*info;
	int		no_path;
	char	*cmd;
	char	**envp;
	char	**args;
	char	**paths;
	char	*path;
}	t_cmd;

void	free_all(t_data *to_free, int code);
void	create_pipe(t_data *data);
void	print_err_and_exit(char *str, t_data *info, int type);
void	init_cmd(t_data *info, char **argv, int argc, char **envp);
void	set_path_type(t_cmd **cmds);
void	set_path(t_cmd **cmds);
char	*find_path(char **envp);
int		check_empty(int argc, char **argv);
void	piping(t_data	*data, int pipes[2]);
void	close_fd(t_data *data, int fd, char *str);
char	*create_file(t_data *info);
#endif