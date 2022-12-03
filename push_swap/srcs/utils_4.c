#include "push.h"

void    actions(t_info *info, t_node **a, t_node **b)
{
    while ((info -> rr--) > 0)
		r_a_b(a, b, 'b', 1);
	while ((info -> rrr--) > 0)
		rr_a_b(a, b, 'b', 1);
	while ((info -> rb--) > 0)
		r_a_b(a, b, 'b', 0);
	while ((info -> rrb--) > 0)
		rr_a_b(a, b, 'b', 0);
	while ((info -> rra--) > 0)
		rr_a_b(a, b, 'a', 0);
	while ((info -> ra--) > 0)
		r_a_b(a, b, 'a', 0);
}

void    lets_push(t_info *info, char name)
{
	t_node  **a;
	t_node  **b;

	a = &info -> a;
	b = &info -> b;
	
	if (info -> rb + info -> ra <= info -> rrb + info -> rra)
	{
		info -> rrb = -1;
		info -> rra = -1;
	}
	else
	{
		info -> ra = -1;
		info -> rb = -1;
	}
	if (info -> ra > 0 && info -> rb > 0)
		set_rr(info);
	if (info -> rra > 0 && info -> rrb)
		set_rrr(info);
    actions(info, a, b);
    if (name == 'b')
	    p_a_b(a, b, 'b');
    else
        p_a_b(a, b, 'a');
}

// void    sort_these_three(t_node **a)
// {

// }

// void    back_to_home(t_info *info)
// {

// }