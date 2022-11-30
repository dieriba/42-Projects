#include "push.h"

static void    push_node_top(t_node **stack, t_node **o_stack, char stack_n)
{
    t_node  *node;

    node = *(o_stack);
    node -> next -> prev = NULL;
    *(o_stack) = node -> next;
    if (!(*stack))
        (*stack) = node;
    else
    {
        (*stack) -> prev = node;
        node -> next = *(stack);
        node -> prev = NULL;
        (*stack) = node;
    }
    if (stack_n == 'a')
        ft_putendl_fd("pa", 1);
    else
        ft_putendl_fd("pb", 1);

}

void    p_a_b(t_node **a, t_node **b, char stack_n)
{
    if (stack_n == 'a' && (*b))
        push_node_top(a, b, stack_n);
    else if (stack_n == 'b' && (*a))
        push_node_top(b, a, stack_n);
}