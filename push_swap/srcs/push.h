#ifndef PUSH_H
#define PUSH_H 

#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line.h"

typedef struct t_node t_node;
typedef struct t_info
{
    t_node  *a;
    t_node  *b;
    int     b_max;
    int     b_min;
    int     a_max;
    int     a_min;
    int     lst_size_a;
    int     lst_size_b;
    int     ra;
    int     rb;
    int     rr;
    int     rra;
    int     rrb;
    int     rrr;
    int     pa;
    int     pb;
    int     argc;
    int     tmp_ra;
    int     tmp_rb;
    int     tmp_rra;
    int     tmp_rrb;
}   t_info;

typedef struct t_node
{
    t_info  *info;
    int     num;
    int     index;
    t_node  *next;
    t_node  *prev;
}   t_node;

void    set_rr(t_info *info);
void    set_rrr(t_info *info);
void    choose_node(t_info *info);
void    find_new_extremum(t_info *info, t_node **a, t_node **b);
void    swapper(t_info *info);
void    init(t_info *info);
void    free_all(t_node **a, t_node **b);
int ft_lstsize_s(t_node *stack);
t_node  *ft_lst_last_s(t_node *stack);
t_node  *create_node(long int num, t_info *info, int argc);
t_node  *ft_lst_add_front_s(t_node **node, t_node *new);
void    p_a_b(t_node **a, t_node **b, char stack_n);
void    r_a_b(t_node **a, t_node **b, char stack, int both);
void    rr_a_b(t_node **a, t_node **b, char stack, int both);
void	s_a_b(t_node **a, t_node **b, char stack, int both);
#endif 