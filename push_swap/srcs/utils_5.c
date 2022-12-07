/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:58:47 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/06 16:58:47 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

void	sort_tab(t_info *info, int *tab)
{
	int	i;
	int	j;
	int	size;
	int	tmp;

	size = info -> lst_size_a;
	i = -1;
	while (++i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
	}
}

int	find_med(t_node **a)
{
	int		*tab;
	t_node	*node;
	int		i;
	int		size;

	size = (*a)-> info -> lst_size_a;
	node = (*a);
	i = -1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	while (++i < size)
	{
		tab[i] = node -> num;
		node = node -> next;
	}
	sort_tab((*a)-> info, tab);
	(*a)-> info -> med = tab[size / 2];
	free(tab);
	return (1);
}

void	sort_these_five(t_node **a, t_node **b)
{
	t_info	*info;

	info = (*a)-> info;
	p_a_b(a, b, 'b');
	info -> b_min = (*b)-> num;
	info -> b_max = (*b)-> num;
	p_a_b(a, b, 'b');
	sort_these_three(&info -> a);
}
