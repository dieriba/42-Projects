#include "push.h"

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

t_node	*ft_lst_last_s(t_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack -> next)
        stack = stack -> next;
    return (stack);
}

t_node	*create_node(long int num, t_info *info, int argc)
{
    t_node	*node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node -> num = num;
    node -> prev = NULL;
    node -> next = NULL;
    node -> info = info;
    node -> index = argc;
    return (node);
}

t_node	*ft_lst_add_front_s(t_node **node, t_node *new)
{
    if (!(*node))
        *(node) = new;
    else
    {
        new -> next = *(node);
        (*node)-> prev = new;
        (*node) = new;
    }
    return (new);
}