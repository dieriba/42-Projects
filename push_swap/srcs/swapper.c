#include "push.h"

t_node    *find_max(t_info *info)
{
	t_node  *b;

	b = info -> b;
	while (b)
	{
		if (b -> num == info -> b_max)
			break;
		b = b -> next;
	}
	return (b);
}

t_node    *set_rb_pos(t_info *info, t_node *node)
{
	t_node  *b;
	t_node  *tmp;
	int     flags;

	flags = 0;
	b = info -> b;
	tmp = node;
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
	if (node == tmp)
		tmp = find_max(info);
	return (tmp);
}

void    find_best_combo(t_info *info, t_node *node)
{
	t_node  *res;

	info -> tmp_ra = info -> ra;
	info -> tmp_rb = info -> rb;
	info -> tmp_rra = info -> rra;
	info -> tmp_rrb = info -> rrb;
	info -> ra = node -> index - 1;
	info -> rra = info -> lst_size_a - node -> index + 1;
	res = set_rb_pos(info, node);
	info -> rb = (res -> index) - 1;
	info -> rrb = info -> lst_size_b - res -> index + 1;
	choose_node(info);
}

void    swapper(t_info *info)
{
	t_node  *node;

	node = info -> a;
	if (info -> lst_size_a > 3)
		while (1)
		{
			while (node)
			{
				find_best_combo(info, node);
				node = node -> next;
			}
			lets_push(info, 'b');
			node = info -> a;
			info -> ra = -1;
			info -> rb = -1;
			info -> rra = -1;
			info -> rrb = -1;
			if (info -> lst_size_a == 3)
				break ;
		}
	// if (info -> lst_size_a == 3)
	// 	sort_these_tree(&info -> a);
	// if (info -> b)
	// 	back_to_home(info);
}