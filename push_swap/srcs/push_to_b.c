#include "push.h"

static t_node    *set_rb_pos(t_info *info, t_node *node,t_node *tmp)
{
	t_node  *b;
	int     flags;

	flags = 0;
	b = info -> b;
	while (b)
	{
		if (node -> num > b -> num && !flags)
		{
			tmp = b;
			flags = 1;
		}
		else if (node -> num == b -> num)
		{
			tmp = b;
			break ;
		}
		if (flags && (node -> num > b-> num) 
			&& (tmp -> num != b -> num) && 
			(tmp -> num < b -> num ))
			tmp = b;
		b = b -> next;
	}
	return (tmp);
}

static void    find_best_combo(t_info *info, t_node *node)
{
	t_node  *res;
	t_node	*tmp;

	tmp = node;
	info -> tmp_ra = node -> index - 1;
	info -> tmp_rra = info -> lst_size_a - node -> index + 1;
	res = set_rb_pos(info, node, tmp);
	if (node == res)
		res = find_max(info, 'b');
	info -> tmp_rb = (res -> index) - 1;
	info -> tmp_rrb = info -> lst_size_b - res -> index + 1;
	choose_node(info);
}

void    go_to_b(t_info *info)
{
	t_node	*node;

    node = info -> a;
	while (1)
	{
		while (node)
		{
			find_best_combo(info, node);
			node = node -> next;
		}
		info -> tmp_ra = -1;
		info -> tmp_rb = -1;
		info -> tmp_rra = -1;
		info -> tmp_rrb = -1;
		info -> tmp_better_opt = -1;
		lets_push(info, 'b');
		node = info -> a;
		info -> better_opt = -1;
		if (node -> info -> lst_size_a == 3)
			break ;
	}
}