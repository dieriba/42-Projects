/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:28:54 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 22:36:51 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	init(t_info *info, int argc, char **argv)
{
	info -> a = 0;
	info -> b = 0;
	info -> ra = -1;
	info -> rb = -1;
	info -> rr = -1;
	info -> rra = -1;
	info -> rrb = -1;
	info -> rrr = -1;
	info -> pa = -1;
	info -> pb = -1;
	info -> better_opt = -1;
	info -> tmp_better_opt = -1;
	info -> b_min = 0;
	info -> b_max = 0;
	info -> lst_size_a = 0;
	info -> lst_size_b = 0;
	info -> argc = argc;
	info -> a_max = ft_atoi(argv[1]);
	info -> a_min = ft_atoi(argv[1]);
}

int	free_all(t_node **a, t_node **b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	while ((*a))
	{
		tmp_a = (*a)-> next;
		free((*a));
		(*a) = NULL;
		(*a) = tmp_a;
	}
	while ((*b))
	{
		tmp_b = (*b)-> next;
		free((*b));
		(*b) = NULL;
		(*b) = tmp_b;
	}
	return (0);
}

void	find_new_extremum_b(t_info *info, t_node **b)
{
	t_node	*node;

	node = (*b);
	if (!node)
		return ;
	info -> b_max = node -> num;
	info -> b_min = node -> num;
	while (node)
	{
		if (info -> b_min > node -> num)
			info -> b_min = node -> num;
		else if (info -> b_max < node -> num)
			info -> b_max = node -> num;
		node = node -> next;
	}
}

void	find_new_extremum_a(t_info *info, t_node **a)
{
	t_node	*node;

	node = (*a);
	if (!node)
		return ;
	info -> a_max = node -> num;
	info -> a_min = node -> num;
	while (node)
	{
		if (info -> a_min > node -> num)
			info -> a_min = node -> num;
		else if (info -> a_max < node -> num)
			info -> a_max = node -> num;
		node = node -> next;
	}
}
