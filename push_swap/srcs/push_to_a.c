/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:44:53 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/08 19:17:16 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static	t_node	*find_min(t_info *info)
{
	t_node	*node;
	int		min;

	min = info -> a_min;
	node = info -> a;
	while (node)
	{
		if (node -> num == min)
			break ;
		node = node -> next;
	}
	return (node);
}

static t_node	*set_ra_pos(t_info *info, t_node *node)
{
	t_node	*a;
	t_node	*tmp;
	int		flags;

	flags = 0;
	a = info -> a;
	tmp = node;
	while (a)
	{
		if (node -> num < a -> num && !flags)
		{
			tmp = a;
			flags = 1;
		}
		else if (node -> num == a -> num)
		{
			tmp = a;
			break ;
		}
		if (flags && (node -> num < a -> num)
			&& (tmp -> num > a -> num))
			tmp = a;
		a = a -> next;
	}
	return (tmp);
}

static void	find_best_combo(t_info *info, t_node *node)
{
	t_node	*res;

	info -> tmp_rb = node -> index - 1;
	info -> tmp_rrb = info -> lst_size_b - node -> index + 1;
	res = set_ra_pos(info, node);
	if (node == res)
		res = find_max(info, 'a');
	if (res -> num < node -> num)
		res = find_min(info);
	info -> tmp_ra = (res -> index) - 1;
	info -> tmp_rra = info -> lst_size_a - res -> index + 1;
	choose_node(info);
}

int	back_to_home(t_info *info)
{
	t_node	*node;

	node = info -> b;
	while (1)
	{
		while (node)
		{
			find_best_combo(info, node);
			node = node -> next;
		}
		info -> better_opt = -1;
		if (!lets_push(info, 'a'))
			return (0);
		node = info -> b;
		if (!node)
			break ;
	}
	return (1);
}
