#include "push.h"

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
	t_node  **a;
	t_node  **b;

	a = &info -> a;
	b = &info -> b;
	if (info -> rb + info -> ra <= info -> rrb + info -> rra)
	{
		info -> rrb = -1;
		info -> rra = -1;
	}
	else
	{
		info -> ra = -1;
		info -> rb = -1;
	}
	if (info -> ra > 0 && info -> rb > 0)
		set_rr(info);
	if (info -> rra > 0 && info -> rrb)
		set_rrr(info);
    actions(info, a, b, name);
}

void    sort_these_three(t_node **a)
{
	t_node	*node;
	int		first;
	int		second;
	int		third;

	node = (*a);
	first = node -> num;
	second = node -> next -> num;
	third = node -> next -> next -> num;
	if (first > second && second < third)
		s_a_b(a, &(*a) -> info -> b, 'a', 0);
	else if (first < second && second > third)
	{
		rr_a_b(a, &(*a) -> info -> b, 'a', 0);
		s_a_b(a, &(*a) -> info -> b, 'a', 0);
	}

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