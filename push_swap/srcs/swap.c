/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:39:48 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/08 15:44:27 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

int	special_case(t_info *info)
{
	if (sorted(&info -> a))
		return (0);
	if (info -> lst_size_a == 3)
	{
		sort_these_three(&info -> a);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	char	**tab;

	if (argc < 2)
		return (1);
	tab = get_args(argc, argv);
	if (!tab)
		return (ft_error(NULL, "Error\n", 1, NULL));
	if (!check(argc, argv, tab))
		return (ft_error(NULL, "Error\n", 1, tab));
	init(&info, argc, argv);
	if (!create_list(tab, &info))
		return (ft_error(&info, "Error\n", 1, tab));
	ft_free_tab(tab);
	if (!special_case(&info))
	{
		free_all(&info.a, &info.b);
		return (0);
	}
	if (!swapper(&info))
		return (1);
	free_all(&info.a, &info.b);
}
