/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:44:24 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 13:44:48 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	go_to_b(t_info *info)
{
	t_node	*node;

	node = info -> a;
	while (node)
	{
		if (node -> num > info -> med)
			p_a_b(&info -> a, &info -> b, 'b');
		else if (node -> num == info -> med)
		{
			p_a_b(&info -> a, &info -> b, 'b');
			if (!find_med(&info -> a))
				return (0);
			node = info -> a;
		}
		else
		{
			if (node -> index)
				r_a_b(&info -> a, &info -> b, 'a', 0);
		}
		if (info -> lst_size_a == 3)
			break ;
		node = info -> a;
	}
	return (1);
}
