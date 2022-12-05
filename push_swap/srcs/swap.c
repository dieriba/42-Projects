#include "push.h"

// int    ft_check(int argc, char **argv)
// {
//     size_t  i;
//     size_t  j;

//     j = -1;
//     i = 0;
//     while(++i < argc)
//     {
//         while (argv[i][++j])
//             if (!ft_isdigit(argv[i][j]))
//                 return (0);
//     }
//     return (1);
// }

int    sorted(t_node **stack)
{
    t_node  *node;
    int     cmp;

    cmp = (*stack) -> info -> a -> num;
    node = (*stack)-> next;
    while (node)
    {
        if (cmp > node -> num)
            return (0);
        cmp = node -> num;
        node = node -> next;
    }
    return (1);
}

int    create_list(int argc, char **argv, t_info *info)
{
    int num;
    t_node  *node;
    while (--argc > 0)
    {
        num = ft_atoi(argv[argc]);
        if (num > info -> a_max)
            info -> a_max = num;
        else if (num < info -> a_min)
            info -> a_min = num;
        node = create_node(ft_atoi(argv[argc]), info, --info -> argc);
        if (!node)
            return (0);
        ft_lst_add_front_s(&info -> a, node);
    }
    return (1);
}

int main (int argc, char **argv)
{
    t_info  info;

    if (argc < 2)
        return (1);
    init(&info);
    info.argc = argc;
    info.a_max = ft_atoi(argv[1]);
    info.a_min = ft_atoi(argv[1]);
    if (!create_list(argc, argv, &info))
        return (1);
    info.lst_size_a = ft_lstsize_s(info.a);
    if (info.lst_size_a == 3)
    {
        sort_these_three(&info.a);
        return (1);
    }
    p_a_b(&info.a, &info.b, 'b');
    info.b_min = info.b -> num;
    info.b_max = info.b -> num;
    p_a_b(&info.a, &info.b, 'b');
    swapper(&info);
    // print_stack(&info.a, 'a');
    if (sorted(&info.a))
        ft_printf("List sorted !\n");
    // print_stack(&info.b, 'b');
    free_all(&info.a, &info.b);
}