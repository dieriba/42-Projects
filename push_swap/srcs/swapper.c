#include "push.h"

t_node	*find_min(t_node **a)
{
	int		min;
	t_node	*node;

	node = (*a);
	min = (*a)-> info -> a_min;
	while (node)
	{
		if (node -> num == min)
			break ;
		node = node -> next;
	}
	return (node);
}

void	ascending_list(t_node **a)
{
	t_node	*node;
	int		rotate;

	node = find_min(a);
	rotate = node -> index;
	while (rotate != 1)
	{
		r_a_b(a, NULL, 'a', 0);
		rotate = node -> index;
	}
}

static void	descending_list(t_info *info)
{
	t_node	*node;
	t_node	**a;
	t_node	**b;
	int		rotate;

	a = &info -> a;
	b = &info -> b;
	node = find_max(info, 'b');
	rotate = node -> index;
	while (rotate != 1)
	{
		r_a_b(a, b, 'b', 0);
		rotate = node -> index;
	}
}

void	swapper(t_info *info)
{
	t_node	*b;

	p_a_b(&info -> a, &info -> b, 'b');
	info -> b_min = info -> b -> num;
	info -> b_max = info -> b -> num;
	p_a_b(&info -> a, &info -> b, 'b');
	go_to_b(info);
	descending_list(info);
	b = info -> b;
	while (b)
	{
		p_a_b(&info -> a, &info -> b, 'a');
		b = info -> b;
	}
}