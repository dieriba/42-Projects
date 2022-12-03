#include "push.h"



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
    int     num;
    init(&info);
    info.argc = argc;
    info.a_max = ft_atoi(argv[1]);
    info.a_min = ft_atoi(argv[1]);
    while (--argc > 0)
    {
        num = ft_atoi(argv[argc]);
        if (num > info.a_max)
            info.a_max = num;
        else if (num < info.a_min)
            info.a_min = num;
        node = create_node(ft_atoi(argv[argc]), &info, --info.argc);
        if (!node)
            return (1);
        ft_lst_add_front_s(&info.a, node);
    }
    info.lst_size_a = ft_lstsize_s(info.a);
    p_a_b(&info.a, &info.b, 'b');
    info.b_min = info.b -> num;
    info.b_max = info.b -> num;
    p_a_b(&info.a, &info.b, 'b');
    // print_stack(&info.b, 'b');
    // ft_printf("\n");
    // ft_printf("\n");
    // print_stack(&info.a, 'a');
    swapper(&info);
    // print_stack(&info.b, 'b');
    // print_index(&info.a);
    // ft_printf("\n");
    // print_index(&info.b);
    // ft_printf("\n");
    // print_stack(&info.a, 'a');
    free_all(&info.a, &info.b);
}