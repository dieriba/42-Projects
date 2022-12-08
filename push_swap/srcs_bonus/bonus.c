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
		return (1);
	else if (!ft_strcmp(line, PB_))
		return (1);
	else if (!ft_strcmp(line, RA_))
		return (1);
	else if (!ft_strcmp(line, RB_))
		return (1);
	else if (!ft_strcmp(line, RRB_))
		return (1);
	else if (!ft_strcmp(line, RRA_))
		return (1);
	else if (!ft_strcmp(line, RRR_))
		return (1);
	else if (!ft_strcmp(line, RR_))
		return (1);
	else if (!ft_strcmp(line, SS_))
		return (1);
	else if (!ft_strcmp(line, SA_))
		return (1);
	else if (!ft_strcmp(line, SB_))
		return (1);
	return (0);
}

void	swap(t_info *info)
{
	char	*line;
	int		size;

	size = info -> lst_size_a;
	while (1)
	{
		line = get_next_line(0, 1);
		if (!check_line(line))
			break ;
		lets_sort(info, line);
		if (!line)
			break ;
		free(line);
	}
	get_next_line(0, 0);
	if (line)
		free(line);
	if (sorted(&info -> a)
		&& info -> lst_size_a == size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	char	**tab;
	t_info	info;

	if (argc < 2)
		return (1);
	tab = get_args(argc, argv);
	if (!tab)
		return (ft_error("Error\n", 0, 0));
	if (!check(argc, argv, tab))
		return (1);
	init(&info, argc, argv);
	if (!create_list(tab, &info))
		return (1);
	swap(&info);
	ft_free_tab(tab);
	free_all(&info.a, &info.b);
}
