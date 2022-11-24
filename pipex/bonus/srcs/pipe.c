/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:44:54 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/24 16:51:15 by dtoure           ###   ########.fr       */
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
	
	i = -1;
	prev_pipes_fd = cmds[0] -> info -> prev_pipes;
	while (cmds[++i] && cmds[i + 1])
	{
		if (pipe(cmds[0]-> info -> pipes) < 0)
			print_err_and_exit("Error", cmds[i]-> info, 1);
		if (i != 0)
		pid_ret = fork();
		if (pid_ret < 0)
			print_err_and_exit("Error", cmds[i]-> info, 1);
		if (pid_ret == 0)
		{
			if (dup2(prev_pipes_fd, STDIN_FILENO) < 0)
				print_err_and_exit("Error", cmds[i]-> info, 1);
			if (close(prev_pipes_fd) < 0)
				print_err_and_exit("Error", cmds[i]-> info, 1);
			if (dup2(cmds[0]-> info -> pipes[1], STDOUT_FILENO) < 0)
				print_err_and_exit("Error", cmds[i]-> info, 1);
			if (close(cmds[0] -> info -> pipes[1]) < 0)
				print_err_and_exit("Error", cmds[i]-> info, 1);
			run_cmd(cmds[i]);
		}
		if (close(prev_pipes_fd) < 0)
			print_err_and_exit("Error", cmds[i]-> info, 1);
		prev_pipes_fd = cmds[0]-> info -> pipes[0];
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
	if (close(fd) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (dup2(pipes[1], STDOUT_FILENO) < 0)
		print_err_and_exit("Error", cmd -> info, 1);
	if (close(pipes[1]) < 0)
		print_err_and_exit("unable not close the pipes", cmd -> info, 0);
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
	if (close(pipes[1]) < 0 || close(pipes[0]) < 0)
		print_err_and_exit("unable close the pipes", cmd -> info, 1);
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
	if (pipe(data -> pipes) < 0)
		print_err_and_exit("unable not set the pipes", data, 1);
	data -> init_pipes = 1;
	pid_ret = fork();
	data -> prev_pipes = data -> pipes[0];
	if (pid_ret < 0)
		print_err_and_exit("unable to fork the process", data, 1);
	if (pid_ret == 0)
		start(data -> cmd_data[0], data -> pipes, data -> files[0]);
	else
	{
		// childs_are_piping(data -> cmd_data);
		pid_ret = fork();
		if (pid_ret < 0)
			print_err_and_exit("unable to fork the process", data, 1);
		if (pid_ret == 0)
			end(data -> cmd_data[1], data -> pipes, data -> prev_pipes, data -> files[1]);
		// if (close(data -> pipes[1]) < 0 || close(data -> pipes[0]) < 0 || close(data -> prev_pipes) < 0)
		// 	print_err_and_exit("unable to close the pipes", data, 1);
		while (wait(NULL) > 0)
			;
	}
}
