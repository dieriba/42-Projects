#include "push.h"

static t_node    *set_rb_pos(t_info *info, t_node *node)
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
		tmp = find_max(info, 'b');
	return (tmp);
}

static void    find_best_combo(t_info *info, t_node *node)
{
	t_node  *res;

	info -> tmp_ra = node -> index - 1;
	info -> tmp_rra = info -> lst_size_a - node -> index + 1;
	res = set_rb_pos(info, node);
	info -> tmp_rb = (res -> index) - 1;
	info -> tmp_rrb = info -> lst_size_b - res -> index + 1;
	//  ft_printf("After some calculations we found that the node : %d should be placed over : %d\n", node -> num, res -> num);
    // ft_printf("Calcul : rra : %d ,rrb : %d ,ra : %d ,rb : %d ,rra + rrb : %d ,ra + rb : %d ,rra + rb : %d ,rrb + ra : %d\n", info -> tmp_rra, info -> tmp_rrb, info -> tmp_ra, info -> tmp_rb
    // ,info -> tmp_rra + info -> tmp_rrb, info -> tmp_ra + info -> tmp_rb,  info -> tmp_rra + info -> tmp_rb, info -> tmp_rrb + info -> tmp_ra);
	choose_node(info);
    // print_stack(&info -> b, 'b');
	// ft_printf("\n");
	// print_stack(&info -> a, 'a');
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
		// ft_printf("We found that the best solution would be to  : rra + rb : %d, rrb + ra : %d, rra + rrb : %d, ra + rb : %d ra : %d, rb : %d, rrb : %d, rra : %d\n",
		// info -> rra + info -> rb, info -> rrb + info -> ra, info -> rra + info -> rrb, info -> ra + info -> rb, info -> ra, info -> rb, info -> rrb, info -> rra);
		lets_push(info, 'b');
		// ft_printf("The node with the value :%d\n", info -> b -> num);
		node = info -> a;
		info -> better_opt = -1;
		if (node -> info -> lst_size_a == 3)
			break ;
	}
}