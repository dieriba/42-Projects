/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:01:23 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/07 14:01:23 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H 

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"

typedef struct t_node	t_node;
typedef struct t_info
{
	t_node	*a;
	t_node	*b;
	int		b_max;
	int		b_min;
	int		a_max;
	int		a_min;
	int		lst_size_a;
	int		lst_size_b;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		pa;
	int		pb;
	int		argc;
	int		tmp_ra;
	int		tmp_rb;
	int		tmp_rra;
	int		tmp_rrb;
	int		better_opt;
	int		tmp_better_opt;
	int		med;
}	t_info;

typedef struct t_node
{
	t_info	*info;
	int		num;
	int		index;
	t_node	*next;
	t_node	*prev;
}	t_node;

char	**get_args(int argc, char **argv);

int		find_med(t_node **a);
int		ft_lstsize_s(t_node *stack);
int		check(int argc, char **argv, char **tab);
int		free_all(t_node **a, t_node **b);
int		go_to_b(t_info *info);
int		swapper(t_info *info);
int		lets_push(t_info *info, char name);
int		back_to_home(t_info *info);
int		ft_error(t_info *info, char *error, int code, char **tab);

t_node	*find_max(t_info *info, char name);
t_node	*ft_lst_last_s(t_node *stack);
t_node	*create_node(long int num, t_info *info, int argc);
t_node	*ft_lst_add_front_s(t_node **node, t_node *new);

void	setter(t_info *info, int min);
void	sort_these_five(t_node **a, t_node **b);
void	sort_these_three(t_node **a);
void	print_stack(t_node **stack, char name);
void	set_rr(t_info *info);
void	set_rrr(t_info *info);
void	choose_node(t_info *info);
void	init(t_info *info, int argc, char **argv);
void	update(char stack_n, t_node **node, t_node **stack);
void	update_stacks(t_node **stack, char name);
void	update_lists(t_node **stack, char name);
void	find_new_extremum_b(t_info *info, t_node **b);
void	find_new_extremum_a(t_info *info, t_node **a);

void	p_a_b(t_node **a, t_node **b, char stack_n);
void	r_a_b(t_node **a, t_node **b, char stack, int both);
void	rr_a_b(t_node **a, t_node **b, char stack, int both);
void	s_a_b(t_node **a, t_node **b, char stack, int both);
#endif
