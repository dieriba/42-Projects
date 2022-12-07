#include "push.h"



int		sorted(t_node **stack)
{
    t_node	*node;
    int		cmp;

    if (!(*stack))
        return (0);
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
    int		num;
    t_node	*node;

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
    info -> lst_size_a = ft_lstsize_s(info -> a);
    return (1);
}

int special_case(t_info *info)
{
    if (sorted(&info -> a))
    {
        ft_printf("List is already sorted\n");
        return (0);
    }
    if (info -> lst_size_a == 3)
    {
        sort_these_three(&info -> a);
        return (0);
    }
    return (1);
}

int main (int argc, char **argv)
{
    t_info	info;
    size_t  i;

    i = -1;
    if (!check(argc, argv))
        return (1);
    init(&info, argc, argv);
    if (!create_list(argc, argv, &info))
        return (1);
    if (!special_case(&info))
    {
        free_all(&info.a, &info.b);
        return (0);
    }
    if (!swapper(&info))
        return (1);
    free_all(&info.a, &info.b);
}