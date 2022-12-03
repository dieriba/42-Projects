#include "push.h"

void    find_new_extremum(t_info *info, t_node **a, t_node **b)
{
    t_node  *node;
	int		flags;

	flags = 0;
    node = (*a);
    while (node)
    {
		if (!flags)
		{
			info -> a_max = node -> num;
			info -> a_min = node -> num;
			flags = 1;
		}
        if (info -> a_min > node -> num)
            info -> a_min = node -> num;
        else if (info -> a_max < node -> num)
            info -> a_max = node -> num;
        node = node -> next;
    }
    node = (*b);
    while (node)
    {
		if (!flags)
		{
			info -> b_max = node -> num;
			info -> b_min = node -> num;
			flags = 1;
		}
        if (info -> b_min > node -> num)
            info -> b_min = node -> num;
        else if (info -> b_max < node -> num)
            info -> b_max = node -> num;
        node = node -> next;
    }
}

int ft_lstsize_s(t_node *stack)
{
    int i;

    if (!(stack))
        return (0);
    i = 0;
    while (stack)
    {
        stack = stack -> next;
        ++i;
    }
    return (i);
}

void    set_rr(t_info *info)
{
	if (info -> ra < info -> rb)
	{
		info -> rr = info -> ra;
		info -> rb = info -> rb - info -> ra;
		info -> ra = -1;
	}
	else if (info -> ra > info -> rb)
	{
		info -> rr = info -> rb;
		info -> ra = info -> ra - info -> rb;
		info -> rb = -1;
	}
	else
	{
		info -> rr = info -> ra;
		info -> rb = -1;
		info -> ra = -1;
	}
}

void    set_rrr(t_info *info)
{
	if (info -> rra < info -> rrb)
	{
		info -> rrr = info -> rra;
		info -> rrb = info -> rrb - info -> rra;
		info -> rra = -1;
	}
	else if (info -> rra > info -> rrb)
	{
		info -> rrr = info -> rrb;
		info -> rra = info -> rra - info -> rrb;
		info -> rrb = -1;
	}
	else
	{
		info -> rrr = info -> rra;
		info -> rrb = -1;
		info -> rra = -1;
	}
}