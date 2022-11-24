/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:44:54 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/24 23:41:13 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(t_cmd *cmd)
{
	size_t	i;

	i = -1;
	if (cmd -> no_path)
	{
		while (cmd -> paths[++i])
		{
			if (access(cmd -> paths[i], F_OK | X_OK) != -1)
				execve(cmd -> paths[i], cmd -> args, cmd -> envp);
		}
	}
	else
		if (access(cmd -> cmd, F_OK | X_OK) != -1)
			execve(cmd -> cmd, cmd -> args, cmd -> envp);
	print_err_and_exit("Error", cmd -> info, 1);
}


void	childs_are_piping(t_cmd **cmds)
{
	int	prev_pipes_fd;
	size_t	i;
	int		pid_ret;
	t_data*	info;

	info = cmds[0]-> info;
	i = -1;
	prev_pipes_fd = cmds[0] -> info -> prev_pipes;
	while (cmds[++i])
	{
		if (pipe(cmds[0] -> info ->pipes) < 0)
			print_err_and_exit("Error", cmds[i]-> info, 1);
		pid_ret = fork();
		if (pid_ret < 0)
			print_err_and_exit("Error", cmds[i]-> info, 1);
		if (i == 0)
		{
			start(cmds[0], info -> pipes, info -> files[0]);
			continue ;
		}
		else if (i == info -> num_cmds - 1)
		{
			end(cmds[0], info -> pipes, info -> prev_pipes, info -> files[1]);
			continue;
		}
		if (pid_ret == 0)
		{
			if (dup2(prev_pipes_fd, STDIN_FILENO) < 0)
				print_err_and_exit("Error", cmds[i]-> info, 1);
			run_cmd(cmds[i]);
		}
		prev_pipes_fd = cmds[0] -> info -> pipes[0];
		if (close(prev_pipes_fd) < 0)
			print_err_and_exit("Error", cmds[i]-> info, 1);
		if (close(cmds[0] -> info -> pipes[1]) < 0)
			print_err_and_exit("Error", cmds[i]-> info, 1);
	}
		
	
}

void	start(t_cmd *cmd, int pipes[2], char *files)
{
	int	fd;
	
	if (access(files, F_OK | R_OK) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	fd = open(files, O_RDONLY, 0666);
	if (fd < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (dup2(fd, STDIN_FILENO) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (dup2(pipes[1], STDOUT_FILENO) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (close(pipes[1]) < 0 || close(pipes[0]))
		print_err_and_exit("Error", cmd -> info, 1);
	run_cmd(cmd);
}

void	end(t_cmd *cmd, int *pipes, int prev_pipes, char *files)
{
	int		fd;
	
	fd = open(files, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (access(files, F_OK | W_OK) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (fd < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (dup2(prev_pipes, STDIN_FILENO) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (close(prev_pipes) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (close(pipes[1]) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (close(fd) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	run_cmd(cmd);
}

void	create_pipe(t_data *data)
{
	char	**files;
	int		pid_ret;

	files = data -> files;
	data -> init_pipes = 1;
	data -> prev_pipes = data -> pipes[0];
	childs_are_piping(data -> cmd_data);
	if (close(data -> pipes[1]) < 0 || close(data -> pipes[0]) < 0)
		print_err_and_exit("Error", data, 1);
	while (wait(NULL) > 0)
		;
}
