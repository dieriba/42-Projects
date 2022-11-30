#include "push.h"

void    print_stack(t_node **stack)
{
    t_node  *node;

    node = *stack;
    while (node)
    {
        ft_printf("----------%d----------\n", node -> num);
        node = node -> next;
    }
}

int main (int argc, char **argv)
{
    t_node  *head;
    t_node  *node;

    head = NULL;
    if (argc < 2)
        return (1);

    while (--argc > 0)
    {
        node = create_node(ft_atoi(argv[argc]));
        if (!node)
            return (1);
        ft_lst_add_front_s(&head, node);
    }
    print_stack(&head);
}