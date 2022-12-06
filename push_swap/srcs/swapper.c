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

int	swapper(t_info *info)
{
	if (info -> lst_size_a == 2)
	{
		if (info -> a -> num > info -> a -> next -> num)
			s_a_b(&info -> a, &info -> b, 'a', 0);
	}
	else if (info -> lst_size_a == 3)
		sort_these_three(&info -> a);
	else if (info -> lst_size_a == 5)
	{
		sort_these_five(&info -> a, &info -> b);
		if (!back_to_home(info))
			return (free_all(&info -> a, &info -> b));
		ascending_list(&info -> a);
	}
	else
	{
		if(!find_med(&info -> a))
			return (free_all(&info -> a, &info -> b));
		if(!go_to_b(info))
			return (free_all(&info -> a, &info -> b));
		sort_these_three(&info -> a);
		if (!back_to_home(info))
			return (free_all(&info -> a, &info -> b));
		ascending_list(&info -> a);
	}
	return (1);
}