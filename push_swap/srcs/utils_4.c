#include "push.h"

int 	find_small(int *options)
{
	size_t	i;
	int		min;
	int		idx;

	i = 0;
	idx = 0;
	min = options[0];
	while (++i < 4)
		if (options[i] < min)
		{
			min = options[i];
			idx = i;
		}
	if (min == options[0])
		return (0);
	return (idx);
}

void	select_best(t_info *info)
{
	int	ra_rb;
	int	rra_rrb;
	int rra_rb;
	int	rrb_ra;
	int	min;

	ra_rb = info -> ra + info -> rb;
	rra_rrb = info -> rra + info -> rrb;
	rra_rb = info -> rra + info -> rb;
	rrb_ra = info -> rrb + info -> ra;
	// ft_printf("Before calc ra_rb : %d, rra_rrb : %d, rra_rb : %d, rrb_ra : %d rra : %d\n", ra_rb, rra_rrb, rra_rb, rrb_ra, info -> rra);
	int	options[4] = {ra_rb, rra_rrb, rra_rb, rrb_ra};
	min = find_small(options);
	if (min == 0)
	{
		info -> rra = -1;
		info -> rrb = -1;
	}
	else if (min == 1)
	{
		info -> ra = -1;
		info -> rb = -1;
	}
	else if (min == 2)
	{
		info -> ra = -1;
		info -> rrb = -1;
	}
	else
	{
		info -> rb = -1;
		info -> rra = -1;
	}
	// ft_printf("Before calc ra_rb : %d, rra_rrb : %d, rra_rb : %d, rrb_ra : %d rra : %d\n", ra_rb, rra_rrb, rra_rb, rrb_ra, info -> rra);
}

void    actions(t_info *info, t_node **a, t_node **b, char name)
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

void    lets_push(t_info *info, char name)
{
	select_best(info);
	// ft_printf("Before ra : %d rb : %d rrb %d rra : %d\n", info -> ra, info -> rb, info -> rrb, info -> rra);
	if ((info -> ra > 0 && info -> rb > 0))
		set_rr(info);
	if ((info -> rra > 0 && info -> rrb > 0))
		set_rrr(info);
	// ft_printf("Before ra : %d rb : %d rrb %d rra : %d\n", info -> ra, info -> rb, info -> rrb, info -> rra);
    actions(info, &info -> a, &info -> b, name);
}

t_node    *find_max(t_info *info, char name)
{
	t_node  *node;
	int		max;

	max = info -> a_max;
	if (name == 'a')
		node = info -> a;
	else
	{
		node = info -> b;
		max = info -> b_max;
	}
	while (node)
	{
		if (node -> num == max)
			break;
		node = node -> next;
	}
	return (node);
}