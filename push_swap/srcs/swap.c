#include "push.h"

void    print_stack(t_node **stack, char name)
{
    t_node  *node;

    node = *stack;
    if (!node)
        ft_printf("Empty list");
    if (name == 'a')
        ft_printf("----------STACK A----------\n");
    else
        ft_printf("----------STACK B----------\n");
    while (node)
    {
        ft_printf("-------------%d-------------\n", node -> num);
        node = node -> next;
    }
}

void    print_index(t_node **stack)
{
    t_node  *tmp;

    tmp = *stack;
    while (tmp)
    {
        ft_printf("number : %d, index : %d\n", tmp -> num, tmp -> index);
        tmp = tmp -> next;
    }
}

void    switch_index(t_node **a)
{
    t_node  *tmp;
    t_info  *info;

    info = (*a) -> info;
    tmp = ft_lst_last_s(*a);
    while (tmp)
    {
        tmp -> index = info -> argc -tmp -> index - 1;
        tmp = tmp -> prev;
    }
}

int main (int argc, char **argv)
{
    if (argc < 2)
        return (1);

    t_node  *node;
    t_info  info;
    init(&info);
    info.argc = argc;
    while (--argc > 0)
    {
        node = create_node(ft_atoi(argv[argc]), &info, --info.argc);
        if (!node)
            return (1);
        ft_lst_add_front_s(&info.a, node);
    }
    info.lst_size = ft_lstsize_s(info.a);
    // switch_index(&info.a);
    // ft_printf("Lst size :%d\n", info.lst_size);
    p_a_b(&info.a, &info.b, 'b');
    p_a_b(&info.a, &info.b, 'b');
    p_a_b(&info.a, &info.b, 'b');
    p_a_b(&info.a, &info.b, 'b');
    p_a_b(&info.a, &info.b, 'b');
    // print_index(&info.a);
    // print_stack(&info.a, 'a');
    ft_printf("\n");
    // print_stack(&info.b, 'b');
    swapper(&info);
    // print_stack(&info.b, 'b');
    // r_a_b(&info.a, &info.b, 'b', 1);
    // r_a_b(&info.a, &info.b, 'b', 1);
    // r_a_b(&info.a, &info.b, 'b', 1);

    // ft_printf("\n");
    // print_stack(&info.a, 'a');
    // ft_printf("\n");
    // print_stack(&info.b, 'b');
    free_all(&info.a, &info.b);
}