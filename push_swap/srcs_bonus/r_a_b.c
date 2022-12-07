/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_a_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:42:57 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 20:12:58 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

static void	update_list(t_node **stack)
{
	t_node	*node;
	int		lst_size;

	lst_size = ft_lstsize_s((*stack));
	node = (*stack);
	while (node -> next)
	{
		node -> index -= 1;
		node = node -> next;
	}
	node -> index = lst_size;
}

static void	switch_first_to_last(t_node **stack, char stack_n)
{
	t_node	*last;
	t_node	*first;

	first = *stack;
	last = ft_lst_last_s((*stack));
	if (first == last)
		return ;
	last -> next = first;
	first -> prev = last;
	(*stack) = first -> next;
	first -> next -> prev = NULL;
	first -> next = NULL;
	if (stack_n == 'a')
		update_list(stack);
	else if (stack_n == 'b')
		update_list(stack);
}

static void	switch_first_last_both(t_node **a, t_node **b)
{
	switch_first_to_last(a, 0);
	if ((*a) && (*a)-> next)
		update_list(a);
	switch_first_to_last(b, 0);
	if ((*b) && (*b)-> next)
		update_list(b);
}

void	r_a_b(t_node **a, t_node **b, char stack, int both)
{
	if (stack == 'a' && ((*a) && ((*a)-> next)) && !both)
		switch_first_to_last(a, 'a');
	else if (stack == 'b' && ((*b) && ((*b)-> next)) && !both)
		switch_first_to_last(b, 'b');
	else if (both && (((*a) && ((*a)-> next)) || ((*b) && ((*b)-> next))))
		switch_first_last_both(a, b);
}
