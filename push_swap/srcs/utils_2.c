/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:34:19 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 16:02:18 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

void	set_rr(t_info *info)
{
	if (info -> ra < info -> rb)
	{
		info -> rr = info -> ra;
		info -> rb = info -> rb - info -> ra;
		info -> ra = -1;
	}
	else if (info -> ra > info -> rb)
	{
		info -> rr = info -> rb;
		info -> ra = info -> ra - info -> rb;
		info -> rb = -1;
	}
	else
	{
		info -> rr = info -> ra;
		info -> rb = -1;
		info -> ra = -1;
	}
}

void	set_rrr(t_info *info)
{
	if (info -> rra < info -> rrb)
	{
		info -> rrr = info -> rra;
		info -> rrb = info -> rrb - info -> rra;
		info -> rra = -1;
	}
	else if (info -> rra > info -> rrb)
	{
		info -> rrr = info -> rrb;
		info -> rra = info -> rra - info -> rrb;
		info -> rrb = -1;
	}
	else
	{
		info -> rrr = info -> rra;
		info -> rrb = -1;
		info -> rra = -1;
	}
}
