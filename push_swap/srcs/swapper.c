#include "push.h"

void    lets_push(t_info *info)
{
    t_node  **a;
    t_node  **b;

    a = &info -> a;
    b = &info -> b;

    while ((info -> rb--) > 0)
        r_a_b(a, b, 'b', 0);
    while ((info -> rrb--) > 0)
        r_a_b(a, b, 'b', 0);
    while ((info -> rra--) > 0)
        r_a_b(a, b, 'a', 0);
    while ((info -> ra--) > 0)
        r_a_b(a, b, 'a', 0);
    p_a_b(a, b, 'b');
}

void    calcul_shortest(t_info *info, t_node *node)
{
    int     min;
    size_t  i;
    t_node  *b;

    i = 0;
    min = 0;
    b = info -> b;
    info -> med = (info -> lst_size / 2);
    info -> ra = node -> index - 1;
    info -> rra = info -> lst_size - node -> index + 1;
    // while (b)
    //     if (node -> num <= b -> num)
    //         info -> rb++;
    // if (info -> rb < 0)
    // if (info -> rb > -1 && i )
    ft_printf("Solution pour place le noeud: %d avec la valeur de : %d,rra : %d, rrb :%d, ra : %d, rb : %d\n",
    node -> index, node -> num, info -> rra, info -> rrb, info -> ra, info -> rb);
}
void    find_best_comb(t_info *info, t_node *node)
{
    calcul_shortest(info, node);
}

void    swapper(t_info *info)
{
    t_node  *node;
    t_node  *tmp;

    tmp = info -> a;
    node = info -> a;
    while (tmp)
    {
        while (node)
        {
            find_best_comb(info, node);
            node = node -> next;
        }
        tmp = tmp -> next;
    }
}