/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:44:54 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 13:49:02 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *str)
{
	perror(str);
	exit(1);
}

void	run_cmd(t_cmd *cmd)
{
	size_t	i;

	i = -1;
	if (cmd -> no_path)
		while (cmd -> paths[++i])
			if (access(cmd -> paths[i], F_OK | X_OK) != -1)
				execve(cmd -> paths[i], cmd -> args, NULL);
	else
		execve(cmd -> cmd, cmd -> args, NULL);
	perror("Error");
}

void	start(t_cmd *cmd, int pipes[2], char *files)
{
	int	fd;

	if (access(files, F_OK | R_OK) < 0)
		exit_error("Error");
	fd = open(files, O_RDONLY, 0666);
	if (fd < 0)
		exit_error("Error");
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipes[1], STDOUT_FILENO);
	close(pipes[1]);
	close(pipes[0]);
	run_cmd(cmd);
}

void	end(t_cmd *cmd, int *pipes, char *files)
{
	int		fd;

	fd = open(files, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (access(files, F_OK | W_OK) < 0)
		exit_error("Error");
	if (fd < 0)
		exit_error("Error");
	dup2(pipes[0], STDIN_FILENO);
	close(pipes[0]);
	close(pipes[1]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	run_cmd(cmd);
}

void	create_pipe(t_data *data)
{
	char	**files;
	int		pid_ret;
	int		pipes[2];

	files = data -> files;
	if (pipe(pipes) < 0)
		print_err_and_exit("Could not set the pipes", data);
	pid_ret = fork();
	if (pid_ret < 0)
		print_err_and_exit("Could not for the process", data);
	if (pid_ret == 0)
		start(data -> cmd_data[0], pipes, data -> files[0]);
	else
	{
		waitpid(pid_ret, NULL, 0);
		pid_ret = fork();
		if (pid_ret < 0)
			print_err_and_exit("Could not for the process", data);
		if (pid_ret == 0)
			end(data -> cmd_data[1], pipes, data -> files[1]);
	}
}