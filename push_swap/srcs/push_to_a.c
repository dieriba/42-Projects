#include "push.h"

static	t_node	*find_min(t_info *info)
{
	t_node  *node;
	int		min;

	min = info -> a_min;
	node = info -> a;
	while (node)
	{
		if (node -> num == min)
			break;
		node = node -> next;
	}
	return (node);
}

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
		if (node -> num < a -> num && !flags)
		{
			tmp = a;
			flags = 1;
		}
		else if (node -> num == a -> num)
		{
			tmp = a;
			break ;
		}
		if (flags && (node -> num < a -> num) 
			&& (tmp -> num > a -> num))
			tmp = a;
		a = a -> next;
	}
	if (node == tmp)
		tmp = find_max(info, 'a');
	if (tmp -> num < node -> num)
		tmp = find_min(info);
	return (tmp);
}

static void    find_best_combo(t_info *info, t_node *node)
{
	t_node  *res;

	info -> tmp_rb = node -> index - 1;
	info -> tmp_rrb = info -> lst_size_b - node -> index + 1;
	res = set_ra_pos(info, node);
	info -> tmp_ra = (res -> index) - 1;
	info -> tmp_rra = info -> lst_size_a - res -> index + 1;
    // ft_printf("After some calculations we found that the node : %d should be placed over : %d\n", node -> num, res -> num);
    // ft_printf("Calcul : rra : %d ,rrb : %d ,ra : %d ,rb : %d ,rra + rrb : %d ,ra + rb : %d ,rra + rb : %d ,rrb + ra : %d\n", info -> tmp_rra, info -> tmp_rrb, info -> tmp_ra, info -> tmp_rb
    // ,info -> tmp_rra + info -> tmp_rrb, info -> tmp_ra + info -> tmp_rb,  info -> tmp_rra + info -> tmp_rb, info -> tmp_rrb + info -> tmp_ra);
	choose_node(info);
    // print_stack(&info -> b, 'b');
	// ft_printf("\n");
    // print_stack(&info -> a, 'a');
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
	// 	ft_printf("the final option Calcul : rra : %d ,rrb : %d ,ra : %d ,rb : %d ,rra + rrb : %d ,ra + rb : %d ,rra + rb : %d ,rrb + ra : %d\n", info -> rra, info -> rrb, info -> ra, info -> rb
    // ,info -> rra + info -> rrb, info -> ra + info -> rb,  info -> rra + info -> rb, info -> rrb + info -> ra);
		info -> tmp_ra = -1;
		info -> tmp_rb = -1;
		info -> tmp_rra = -1;
		info -> tmp_rrb = -1;
		info -> better_opt = -1;
		lets_push(info, 'a');
		node = info -> b;
		if (!node)
			break ;
	}
}