/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:29:41 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 13:31:09 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	find_small(int *options)
{
	size_t	i;
	int		min;
	int		idx;

	i = 0;
	idx = 0;
	min = options[0];
	while (++i < 4)
	{
		if (options[i] < min)
		{
			min = options[i];
			idx = i;
		}
	}
	if (min == options[0])
		return (0);
	return (idx);
}

int	create_tab(int ra_rb, int rra_rrb, int rra_rb, int rrb_ra)
{
	int	*tab;
	int	min;

	min = -1;
	tab = malloc(sizeof(int) * 4);
	if (!tab)
		return (min);
	tab[0] = ra_rb;
	tab[1] = rra_rrb;
	tab[2] = rra_rb;
	tab[3] = rrb_ra;
	min = find_small(tab);
	free(tab);
	return (min);
}

int	select_best(t_info *info)
{
	int	min;

	min = create_tab(info -> ra + info -> rb, info -> rra + info -> rrb,
			info -> rra + info -> rb, info -> rrb + info -> ra);
	if (min == -1)
		return (0);
	setter(info, min);
	return (1);
}

void	actions(t_info *info, t_node **a, t_node **b, char name)
{
	while ((info -> rr--) > 0)
		r_a_b(a, b, 'b', 1);
	while ((info -> rrr--) > 0)
		rr_a_b(a, b, 'b', 1);
	while ((info -> rb--) > 0)
		r_a_b(a, b, 'b', 0);
	while ((info -> rrb--) > 0)
		rr_a_b(a, b, 'b', 0);
	while ((info -> rra--) > 0)
		rr_a_b(a, b, 'a', 0);
	while ((info -> ra--) > 0)
		r_a_b(a, b, 'a', 0);
	if (name == 'a')
		p_a_b(a, b, 'a');
	else
		p_a_b(a, b, 'b');
}

int	lets_push(t_info *info, char name)
{
	if (!select_best(info))
		return (0);
	if ((info -> ra > 0 && info -> rb > 0))
		set_rr(info);
	if ((info -> rra > 0 && info -> rrb > 0))
		set_rrr(info);
	actions(info, &info -> a, &info -> b, name);
	return (1);
}
