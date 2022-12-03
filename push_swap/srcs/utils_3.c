#include "push.h"

void    choose_node(t_info *info)
{
    if (info -> tmp_ra != -1 && info -> tmp_rb != -1)
		if (info -> tmp_ra + info -> tmp_rb <= info -> ra + info -> rb)
		{
			info -> ra = info -> tmp_ra;
			info -> rb = info -> tmp_rb;
		}
	if (info -> tmp_rra != -1 && info -> tmp_rrb != -1)
		if (info -> tmp_rra + info -> tmp_rrb <= info -> rra + info -> rrb)
		{
			info -> rra = info -> tmp_rra;
			info -> rrb = info -> tmp_rrb;
		}
}

void    print_stack(t_node **stack, char name)
{
    t_node  *node;

    node = *stack;
    if (!node)
        ft_printf("Empty list");
    if (name == 'a')
        ft_printf("\tSTACK A\t\n");
    else
        ft_printf("\tSTACK B\t\n");
    while (node)
    {
        ft_printf("\t%d\t\n", node -> num);
        node = node -> next;
    }
}