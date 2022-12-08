/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:34:12 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 22:34:12 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	print(t_info *info, int size, int err)
{
	if (!err && sorted(&info -> a)
		&& info -> lst_size_a == size)
		ft_printf("OK\n");
	else if (err)
		ft_putstr_fd("Error\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
}

void	lets_sort(t_info *info, char *actions)
{
	if (!actions)
		return ;
	if (!ft_strcmp(actions, PA_))
		p_a_b(&info -> a, &info -> b, 'a');
	else if (!ft_strcmp(actions, PB_))
		p_a_b(&info -> a, &info -> b, 'b');
	else if (!ft_strcmp(actions, RA_))
		r_a_b(&info -> a, &info -> b, 'a', 0);
	else if (!ft_strcmp(actions, RB_))
		r_a_b(&info -> a, &info -> b, 'b', 0);
	else if (!ft_strcmp(actions, RRA_))
		rr_a_b(&info -> a, &info -> b, 'a', 0);
	else if (!ft_strcmp(actions, RRB_))
		rr_a_b(&info -> a, &info -> b, 'b', 0);
	else if (!ft_strcmp(actions, RR_))
		r_a_b(&info -> a, &info -> b, 'b', 1);
	else if (!ft_strcmp(actions, RRR_))
		rr_a_b(&info -> a, &info -> b, 'a', 1);
	else if (!ft_strcmp(actions, SA_))
		s_a_b(&info -> a, &info -> b, 'a', 0);
	else if (!ft_strcmp(actions, SB_))
		s_a_b(&info -> a, &info -> b, 'b', 0);
	else if (!ft_strcmp(actions, SS_))
		s_a_b(&info -> a, &info -> b, 'a', 1);
}

int	check_line(char *line)
{
	if (!line)
		return (0);
	if (!ft_strcmp(line, PA_))
		return (0);
	else if (!ft_strcmp(line, PB_))
		return (0);
	else if (!ft_strcmp(line, RA_))
		return (0);
	else if (!ft_strcmp(line, RB_))
		return (0);
	else if (!ft_strcmp(line, RRB_))
		return (0);
	else if (!ft_strcmp(line, RRA_))
		return (0);
	else if (!ft_strcmp(line, RRR_))
		return (0);
	else if (!ft_strcmp(line, RR_))
		return (0);
	else if (!ft_strcmp(line, SS_))
		return (0);
	else if (!ft_strcmp(line, SA_))
		return (0);
	else if (!ft_strcmp(line, SB_))
		return (0);
	return (1);
}

void	swap(t_info *info)
{
	char	*line;
	int		size;
	int		err;

	err = 0;
	size = info -> lst_size_a;
	while (1)
	{
		line = get_next_line(0, 1);
		err = check_line(line);
		if (err)
			break ;
		lets_sort(info, line);
		if (!line)
			break ;
		free(line);
	}
	get_next_line(0, 0);
	if (line)
		free(line);
	print(info, size, err);
}

int	main(int argc, char **argv)
{
	char	**tab;
	t_info	info;

	if (argc < 2)
		return (1);
	tab = get_args(argc, argv);
	if (!tab)
		return (ft_error(0, "Error\n", 1, 0));
	if (!check(argc, argv, tab))
		return (ft_error(NULL, "Error\n", 1, tab));
	init(&info, argc, argv);
	if (!create_list(tab, &info))
		return (ft_error(&info, "Error\n", 1, tab));
	ft_free_tab(tab);
	swap(&info);
	free_all(&info.a, &info.b);
}
