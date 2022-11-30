#include "push.h"

static void    switch_last_to_first(t_node **stack, char stack_n)
{
    t_node  *last;
    t_node  *first;

    first = *stack;
    last = ft_lst_last_s((*stack));
    first -> prev = last;
    last -> next = first;
    last -> prev -> next = NULL;
    last -> prev = NULL;
    *stack = last;
    if (stack_n == 'a')
        ft_putendl_fd("rra", 1);
    else if (stack_n == 'b')
        ft_putendl_fd("rrb", 1);
}

static void    switch_last_first_both(t_node **a, t_node **b)
{
    switch_last_to_first(a, 0);
    switch_last_to_first(b, 0);
    ft_putendl_fd("rrr", 1);
}

void    rr_a_b(t_node **a, t_node **b, char stack, int both)
{
    if (stack == 'a' && (*a) && ((*a )-> next) && !both)
        switch_last_to_first(a, 'a');
    else if (stack == 'b' && (*b) && ((*b) -> next) && !both)
        switch_last_to_first(b, 'b');
    else if (both && ((*a) && ((*a) -> next)) && ((*b) && ((*b) -> next)))
        switch_last_first_both(a, b);
}