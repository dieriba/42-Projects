#include "push.h"

static t_node    *set_ra_pos(t_info *info, t_node *node)
{
	t_node  *a;
	t_node  *tmp;
	int     flags;

	flags = 0;
	a = info -> a;
	tmp = node;
        
	while (a)
	{
		if (node -> num > a -> num && !flags)
		{
			tmp = a;
			flags = 1;
		}
		else if (node -> num == a -> num)
		{
			tmp = a;
			break ;
		}
		if (flags && (node -> num > a -> num) 
			&& (tmp -> num != a -> num) && 
			(tmp -> num < a -> num ))
			tmp = a;
		a = a -> next;
	}
	if (node == tmp)
		tmp = find_max(info, 'a');
	return (tmp);
}

static void    find_best_combo(t_info *info, t_node *node)
{
	t_node  *res;

	info -> tmp_ra = info -> ra;
	info -> tmp_rb = info -> rb;
	info -> tmp_rra = info -> rra;
	info -> tmp_rrb = info -> rrb;
	info -> rb = node -> index - 1;
	info -> rrb = info -> lst_size_b - node -> index + 1;
	res = set_ra_pos(info, node);
	info -> ra = (res -> index) - 1;
	info -> rra = info -> lst_size_a - res -> index + 1;
	choose_node(info);
}

void    back_to_home(t_info *info)
{
	t_node	*node;

    node = info -> b;
	while (1)
	{
		while (node)
		{
			find_best_combo(info, node);
			node = node -> next;
		}
		lets_push(info, 'a');
		node = info -> b;
		info -> ra = -1;
		info -> rb = -1;
		info -> rra = -1;
		info -> rrb = -1;
		if (!node)
			break ;
	}
}