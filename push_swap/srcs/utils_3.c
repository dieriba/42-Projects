#include "push.h"

int     who_smallest(int first, int second, int third, int fourth)
{
    int min;

    min = first;
    if (second < min)
        min = second;
    if (third < min)
        min = third;
    if (fourth < min)
        min = fourth;
    return (min);
}

void    choose_node(t_info *info)
{
    int ra_rb;
    int rra_rrb;
    int rra_rb;
    int rrb_ra;

    ra_rb = info -> tmp_ra + info -> tmp_rb;
    rra_rrb = info -> tmp_rra + info -> tmp_rrb;
    rrb_ra = info -> tmp_rrb + info -> tmp_ra;
    rra_rb = info -> tmp_rra + info -> tmp_rb;
    info -> tmp_better_opt = who_smallest(rra_rrb, ra_rb, rra_rb, rrb_ra);
    if (info -> better_opt == -1)
    {   
        info -> better_opt = info -> tmp_better_opt;
        info -> ra = info -> tmp_ra;
        info -> rb = info -> tmp_rb;
        info -> rra = info -> tmp_rra;
        info -> rrb = info -> tmp_rrb;
    }
    else if (info -> better_opt != -1 && info -> tmp_better_opt < info -> better_opt)
    {
        info -> ra = info -> tmp_ra;
        info -> rb = info -> tmp_rb;
        info -> rra = info -> tmp_rra;
        info -> rrb = info -> tmp_rrb;
	    info -> better_opt = info -> tmp_better_opt;
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