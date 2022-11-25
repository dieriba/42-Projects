/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:58:19 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/25 23:18:19 by dtoure           ###   ########.fr       */
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
			if (access(cmd -> paths[i], X_OK) != -1)
				execve(cmd -> paths[i], cmd -> args, cmd -> envp);
		}
	}
	else
		if (access(cmd -> cmd, X_OK) != -1)
			execve(cmd -> cmd, cmd -> args, cmd -> envp);
	print_err_and_exit("pipex", cmd -> info, 1);
}

void	start(t_cmd *cmd, int pipes[2])
{
	char	*file;
	int		fd;

	file = cmd -> info -> files[0]-> file;
	if (access(file, F_OK | R_OK) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	fd = open(file, O_RDONLY);
	cmd -> info -> files[0]-> fd = fd;
	if (fd < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (dup2(fd, STDIN_FILENO) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (close(fd) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (dup2(pipes[1], STDOUT_FILENO) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (close(pipes[1]) < 0 || close(pipes[0]))
		print_err_and_exit("Pipex ", cmd -> info, 1);
	run_cmd(cmd);
}

void	end(t_cmd *cmd, int pipes[2], int prev_pipes)
{
	char	*file;
	int		fd;

	file = cmd -> info -> files[1]-> file;
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	cmd -> info -> files[1]-> fd = fd;
	if (access(file, W_OK) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (fd < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (dup2(prev_pipes, STDIN_FILENO) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (close(pipes[0]) < 0 || close(pipes[1]) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	if (close(fd) < 0 || close(prev_pipes) < 0)
		print_err_and_exit("Pipex ", cmd -> info, 1);
	run_cmd(cmd);
}

void	forking(t_data *data, int pipes[2], int i)
{
	t_cmd	**cmds;

	cmds = data -> cmd_data;
	if (i == 0)
		start(data -> cmd_data[0], pipes);
	else if (i == data -> num_cmds - 1)
		end(cmds[i], pipes, data -> prev_pipes);
	else
	{
		if (data -> prev_pipes != -1)
		{
			if (dup2(data -> prev_pipes, STDIN_FILENO) < 0)
				print_err_and_exit("Pipex ", data, 1);
			if (close(data -> prev_pipes) < 0)
				print_err_and_exit("Pipex ", data, 1);
		}
		if (dup2(pipes[1], STDOUT_FILENO) < 0)
			print_err_and_exit("Pipex ", data, 1);
		if (close(pipes[1]) < 0 || close(pipes[0]) < 0)
			print_err_and_exit("Pipex ", data, 1);
		run_cmd(cmds[i]);
	}
}

void	piping(t_data	*data, int pipes[2])
{
	int		i;
	t_cmd	**cmds;
	int		pid_ret;

	cmds = data -> cmd_data;
	i = -1;
	while (cmds[++i])
	{
		if (pipe(pipes) < 0)
			print_err_and_exit("pipex", data, 1);
		data -> init_pipes = 1;
		pid_ret = fork();
		if (pid_ret < 0)
			print_err_and_exit("pipex", data, 1);
		if (pid_ret == 0)
			forking(data, pipes, i);
		if (data -> prev_pipes != -1)
			close_fd(data, data -> prev_pipes, "pipex");
		data -> prev_pipes = pipes[0];
		close_fd(data, data -> pipes[1], "pipex");
	}
	close_fd(data, data -> prev_pipes, "pipex");
	while (wait(NULL) > 0)
		;
}
