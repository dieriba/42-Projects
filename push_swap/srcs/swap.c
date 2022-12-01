#include "push.h"

void    print_stack(t_node **stack)
{
    t_node  *node;

    node = *stack;
    if (!node)
        ft_printf("Empty list");
    while (node)
    {
        ft_printf("----------%d----------\n", node -> num);
        node = node -> next;
    }
}

int main (int argc, char **argv)
{
    if (argc < 2)
        return (1);

    t_node  *node;
    t_info  info;
    init(&info);
    while (--argc > 0)
    {
        node = create_node(ft_atoi(argv[argc]));
        if (!node)
            return (1);
        ft_lst_add_front_s(&info.a, node);
    }
    print_stack(&info.a);
    rr_a_b(&info.a, &info.b, 'a',0);
    // ft_printf("\n");
}