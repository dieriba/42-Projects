/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:39:48 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/08 15:47:02 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	sorted(t_node **stack)
{
	t_node	*node;
	int		cmp;

	if (!(*stack))
		return (0);
	cmp = (*stack)-> info -> a -> num;
	node = (*stack)-> next;
	while (node)
	{
		if (cmp > node -> num)
			return (0);
		cmp = node -> num;
		node = node -> next;
	}
	return (1);
}

int	create_list(char **argv, t_info *info)
{
	int		num;
	t_node	*node;
	int		tablen;

	tablen = ft_tab_len(argv);
	tablen--;
	while (tablen >= 0)
	{
		num = ft_atoi(argv[tablen]);
		if (num > info -> a_max)
			info -> a_max = num;
		else if (num < info -> a_min)
			info -> a_min = num;
		node = create_node(ft_atoi(argv[tablen]), info, tablen + 1);
		if (!node)
			return (0);
		ft_lst_add_front_s(&info -> a, node);
		tablen--;
	}
	info -> lst_size_a = ft_lstsize_s(info -> a);
	return (1);
}

int	ft_error(t_info *info, char *error, int code, char **tab)
{
	ft_putstr_fd(error, 2);
	if (tab)
		ft_free_tab(tab);
	if (info)
		free_all(&info -> a, &info -> b);
	return (code);
}
