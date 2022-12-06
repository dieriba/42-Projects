#include "push.h"

int    go_to_b(t_info *info)
{
	t_node	*node;

    node = info -> a;
	while (node)
	{
		if (node -> num > info -> med)
			p_a_b(&info -> a, &info -> b, 'b');
		else if (node -> num == info -> med)
		{
			p_a_b(&info -> a, &info -> b, 'b');
			if (!find_med(&info -> a))
				return (0);
			node = info -> a;
		}
		else
		{
			if (node -> index)
				r_a_b(&info -> a, &info -> b, 'a', 0);
		}
		if (info -> lst_size_a == 3)
			break ;
		node = info -> a;
	}
	return (1);
}