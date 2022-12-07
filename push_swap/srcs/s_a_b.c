/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_a_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:42:06 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 13:42:06 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	swap_two_f_elems(t_node *a, t_node *b, char stack_n)
{
	int	first;

	first = b -> num;
	b -> num = a -> num;
	a -> num = first;
	if (stack_n == 'a')
		ft_putendl_fd("sa", 1);
	else if (stack_n == 'b')
		ft_putendl_fd("sb", 1);
}

static void	swap_both_first_t_node(t_node *a, t_node *a_next,
	t_node *b, t_node *b_next)
{
	swap_two_f_elems(a, a_next, 0);
	swap_two_f_elems(b, b_next, 0);
	ft_putendl_fd("ss", 1);
}

void	s_a_b(t_node **a, t_node **b, char stack, int both)
{
	if (stack == 'a' && ((*a) && ((*a)-> next)) && !both)
		swap_two_f_elems((*a), ((*a)-> next), 'a');
	else if (stack == 'b' && ((*b) && ((*b)-> next)) && !both)
		swap_two_f_elems((*b), ((*b)-> next), 'b');
	else if (both && ((*a) && (*a)-> next) && ((*b) && (*b)-> next))
		swap_both_first_t_node((*a), (*a)-> next, (*b), (*b)-> next);
}
