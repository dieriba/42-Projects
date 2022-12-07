#include "push.h"

t_node    *find_max(t_info *info, char name)
{
	t_node  *node;
	int		max;

	max = info -> a_max;
	if (name == 'a')
		node = info -> a;
	else
	{
		node = info -> b;
		max = info -> b_max;
	}
	while (node)
	{
		if (node -> num == max)
			break;
		node = node -> next;
	}
	return (node);
}

int     who_smallest(t_info *info)
{
    int min;
    int ra_rb;
    int rra_rrb;
    int rra_rb;
    int rrb_ra;

    ra_rb = info -> tmp_ra + info -> tmp_rb;
    rra_rrb = info -> tmp_rra + info -> tmp_rrb;
    rrb_ra = info -> tmp_rrb + info -> tmp_ra;
    rra_rb = info -> tmp_rra + info -> tmp_rb;
    min = ra_rb;
    if (rra_rrb < min)
        min = rra_rrb;
    if (rrb_ra < min)
        min = rrb_ra;
    if (rra_rb < min)
        min = rra_rb;
    return (min);
}

void    choose_node(t_info *info)
{ 
    info -> tmp_better_opt = who_smallest(info);
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
        ft_printf("\tValue : %d Index : %d\t\n", node -> num, node -> index);
        node = node -> next;
    }
}

void	setter(t_info *info, int min)
{
	if (min == 0)
	{
		info -> rra = -1;
		info -> rrb = -1;
	}
	else if (min == 1)
	{
		info -> ra = -1;
		info -> rb = -1;
	}
	else if (min == 2)
	{
		info -> ra = -1;
		info -> rrb = -1;
	}
	else
	{
		info -> rb = -1;
		info -> rra = -1;
	}
}

int ft_error(char *error, int code, char **tab)
{
    ft_putstr_fd(error, 2);
    if (tab)
        ft_free_tab(tab);
    return (code);
}