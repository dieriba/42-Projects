/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:35:22 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 14:02:32 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_lstsize_s(t_node *stack)
{
	int	i;

	if (!(stack))
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack -> next;
		++i;
	}
	return (i);
}

t_node	*ft_lst_last_s(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

t_node	*create_node(long int num, t_info *info, int argc)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> num = num;
	node -> prev = NULL;
	node -> next = NULL;
	node -> info = info;
	node -> index = argc;
	return (node);
}

t_node	*ft_lst_add_front_s(t_node **node, t_node *new)
{
	if (!(*node))
		*(node) = new;
	else
	{
		new -> next = *(node);
		(*node)-> prev = new;
		(*node) = new;
	}
	return (new);
}

void	update(char stack_n, t_node **node, t_node **stack)
{
	if (stack_n == 'a')
	{
		ft_putendl_fd("pa", 1);
		update_lists(node, 'b');
		update_stacks(stack, 'a');
	}
	else
	{
		ft_putendl_fd("pb", 1);
		update_lists(node, 'a');
		update_stacks(stack, 'b');
	}
}
