#include "push.h"

void    init(t_info *info, int argc, char **argv)
{
    info -> a = 0;
    info -> b = 0;
    info -> ra = -1;
    info -> rb = -1;
    info -> rr = -1;
    info -> rra = -1;
    info -> rrb = -1;
    info -> rrr = -1;
    info -> pa = -1;
    info -> pb = -1;
    info -> better_opt = -1;
    info -> tmp_better_opt = -1;
    info -> b_min = 0;
    info -> b_max = 0;
    info -> lst_size_a = 0;
    info -> lst_size_b = 0;
    info -> argc = argc;
    info -> a_max = ft_atoi(argv[1]);
    info -> a_min = ft_atoi(argv[1]);
}

void	free_all(t_node **a, t_node **b)
{
    t_node	*tmp_a;
    t_node	*tmp_b;

    tmp_a = NULL;
    tmp_b = NULL;
    while ((*a))
    {
        tmp_a = (*a)-> next;
        free((*a));
        (*a) = NULL;
        (*a) = tmp_a;
    }
    while ((*b))
    {
        tmp_b = (*b)-> next;
        free((*b));
        (*b) = NULL;
        (*b) = tmp_b;
    }
}