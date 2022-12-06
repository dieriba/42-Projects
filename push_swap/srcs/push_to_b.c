#include "push.h"

void    go_to_b(t_info *info)
{
	t_node	*node;

    node = info -> a;
	find_med(&node);
	while (node)
	{
		if (node -> num > info -> med)
			p_a_b(&info -> a, &info -> b, 'b');
		else if (node -> num == info -> med)
		{
			p_a_b(&info -> a, &info -> b, 'b');
			find_med(&info -> a);
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
}