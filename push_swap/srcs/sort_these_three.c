/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_these_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:41:24 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 13:41:24 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	case_one(t_node **a)
{
	s_a_b(a, 0, 'a', 0);
	r_a_b(a, 0, 'a', 0);
}

void	case_two(t_node **a)
{
	s_a_b(a, 0, 'a', 0);
	rr_a_b(a, 0, 'a', 0);
}

void	case_three(t_node **a)
{
	s_a_b(a, 0, 'a', 0);
}

void	case_four(t_node **a)
{
	r_a_b(a, 0, 'a', 0);
}

void	sort_these_three(t_node **a)
{
	t_node	*node;
	int		first;
	int		second;
	int		third;

	node = (*a);
	first = node -> num;
	second = node -> next -> num;
	third = node -> next -> next -> num;
	if (first < second && second > third && first < third)
		case_one(a);
	else if (first > second && second > third && first > third)
		case_two(a);
	else if (first > second && second < third && third > first)
		case_three(a);
	else if (first > second && second < third && first > third)
		case_four(a);
	else if (first < second && second > third && first > third)
		rr_a_b(a, 0, 'a', 0);
}
