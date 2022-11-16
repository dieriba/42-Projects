/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:50:30 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/16 14:50:30 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	is_process_running(pid_t pid, char *msg)
{
	if (kill(pid, 0) < 0)
	{
		ft_putstr_fd(("An error occured during the process, exiting...\n"), 2);
		if (msg)
			free(msg);
		exit(EXIT_FAILURE);
	}
}
