#include "push.h"

static	void	delete_node(t_node **stack)
{
	t_node	*next;

	next = NULL;
	if ((*stack) -> next)
		next = ((*stack) -> next);
	if (!next)
	{
		(*stack) = NULL;
		return ;
	}
	next -> prev = NULL;
	(*stack) = next; 
}

static void    push_node_top(t_node **node, t_node **stack, char stack_n)
{
	t_node	*next_n;
	t_node	*curr_n;

	curr_n = NULL;
	next_n = NULL;
	if (!(*stack))
	{
		curr_n = (*node);
		delete_node(node);
		(*stack) = curr_n;
		(*stack) -> next = NULL;
	}
	else
	{
		next_n = (*stack);
		curr_n = (*node);
		delete_node(node);
		curr_n -> next = next_n;
		next_n -> prev = (*stack);
		(*stack) = curr_n;
	}
	if (stack_n == 'a')
		ft_putendl_fd("pa", 1);
	else
		ft_putendl_fd("pb", 1);
}

void    p_a_b(t_node **a, t_node **b, char stack_n)
{
	if (stack_n == 'a' && (*b))
		push_node_top(b, a, stack_n);
	else if (stack_n == 'b' && (*a))
		push_node_top(a, b, stack_n);
}