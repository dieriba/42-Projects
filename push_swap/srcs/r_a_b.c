#include "push.h"

static void    switch_first_to_last(t_node **stack, char stack_n)
{
    t_node  *last;
    t_node  *first;

    first = *stack;
    last = ft_lst_last_s((*stack));
    last -> next = first;
    first -> prev = last;
    (*stack) = first -> next;
    first -> next -> prev = NULL;
    first -> next = NULL;
    if (stack_n == 'a')
        ft_putendl_fd("ra", 1);
    else if (stack_n == 'b')
        ft_putendl_fd("rb", 1);
}

static void    switch_first_last_both(t_node **a, t_node **b)
{
    switch_first_to_last(a, 0);
    switch_first_to_last(b, 0);
    ft_putendl_fd("rr", 1);
}

void    r_a_b(t_node **a, t_node **b, char stack, int both)
{
    if (stack == 'a' && ((*a) && ((*a) -> next)) && !both)
        switch_first_to_last(a, 'a');
    else if (stack == 'b' && ((*b) && ((*b) -> next)) && !both)
        switch_first_to_last(b, 'b');
    else if (both && ((*a) && ((*a) -> next)) && ((*b) && ((*b) -> next)))
        switch_first_last_both(a, b);
}