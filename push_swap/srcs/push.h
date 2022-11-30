#ifndef PUSH_H
#define PUSH_H 

#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line.h"

typedef struct t_node t_node;
typedef struct t_node
{
    int     num;
    t_node  *next;
    t_node  *prev;
}   t_node;

void    free_all(t_node **a, t_node **b);
int ft_lstsize_s(t_node **stack);
t_node  *ft_lst_last_s(t_node *stack);
t_node  *create_node(long int num);
t_node  *ft_lst_add_front_s(t_node **node, t_node *new);
void    p_a_b(t_node **a, t_node **b, char stack_n);
void    r_a_b(t_node **a, t_node **b, char stack, int both);
void    rr_a_b(t_node **a, t_node **b, char stack, int both);
void	s_a_b(t_node **a, t_node **b, char stack, int both);
#endif 