#include "push.h"

void    init(t_info *info)
{
    info -> a = 0;
    info -> b = 0;
    info -> med = 0;
    info -> ra = -1;
    info -> rb = -1;
    info -> rr = -1;
    info -> rra = -1;
    info -> rrb = -1;
    info -> rrr = -1;
    info -> pa = -1;
    info -> pb = -1;
    info -> sa = -1;
    info -> sb = -1;
    info -> ss = -1;
}

void    free_all(t_node **a, t_node **b)
{
    t_node  *last_a;
    t_node  *last_b;
    t_node  *tmp;

    last_a = ft_lst_last_s(*(a));
    last_b = ft_lst_last_s(*(b));
    while (last_a)
    {
        tmp = last_a -> prev;
        free(last_a);
        last_a = tmp;
    }
    if (a)
        free(a);
    while (last_b)
    {
        tmp = last_a -> prev;
        free(last_a);
        last_b = tmp;
    }
    if (b)
        free(b);
}

int ft_lstsize_s(t_node **stack)
{
    int i;

    if (!(*stack))
        return (0);
    i = -1;
    while ((*stack))
    {
        (*stack) = (*stack) -> next;
        ++i;
    }
    return (i);
}

t_node  *ft_lst_last_s(t_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack -> next)
        stack = stack -> next;
    return (stack);
}

t_node  *create_node(long int num)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node -> num = num;
    node -> prev = NULL;
    node -> next = NULL;
    return (node);
}

t_node  *ft_lst_add_front_s(t_node **node, t_node *new)
{
    if (!(*node))
        *(node) = new;
    else
    {
        new -> next = *(node);
        (*node) -> prev = new;
        (*node) = new;
    }
    return (new);
}