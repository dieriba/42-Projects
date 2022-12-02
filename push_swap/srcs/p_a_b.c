#include "push.h"

static void	update_list(t_node **stack, char name)
{
	t_node	*ptr;


	ptr = (*stack);
	while (ptr)
	{
		ptr -> index = (ptr -> index) - 1;
		ptr = ptr -> next;
	}
	if (name == 'a')
		(*stack) -> info -> lst_size_a -= 1;
	else
		(*stack) -> info -> lst_size_b -= 1;
}

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

static	void	update_stack(t_node **stack, char name)
{
	t_node	*b;
	int		index;

	index = 0;
	b = (*stack);
	while (b)
	{
		++index;
		b -> index = index;
		b = b -> next;
	}
	if (name == 'a')
		(*stack) -> info -> lst_size_a += 1;
	else
		(*stack) -> info -> lst_size_b += 1;
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
		(*stack) = curr_n;
		next_n -> prev = (*stack);
	}
	if (stack_n == 'a')
	{
		ft_putendl_fd("pa", 1);
		update_list(node, 'b');
		update_stack(stack, 'a');
	}
	else
	{
		if ((*stack) -> num > (*stack) -> info -> b_max)
			(*stack) -> info -> b_max = (*stack) -> num;
		else if ((*stack) -> num < (*stack) -> info -> b_min)
			(*stack) -> info -> b_min = (*stack) -> num;
		ft_putendl_fd("pb", 1);
		update_list(node, 'a');
		update_stack(stack, 'b');
	}
}

void    p_a_b(t_node **a, t_node **b, char stack_n)
{
	if (stack_n == 'a' && (*b))
		push_node_top(b, a, stack_n);
	else if (stack_n == 'b' && (*a))
		push_node_top(a, b, stack_n);
	find_new_extremum((*a) -> info, a, b);
}